//  weibo:   https://weibo.com/u/2738662791
//  twitter: https://twitter.com/u0x01
//
//  bluedhook.mm
//  bluedhook.Dylib
//
//  Created by u0x01 on 2021/10/20.
//  Copyright (c) 2021 u0x01. All rights reserved.
//
// 本项目支持 Blued、Blued 极速版

#if TARGET_OS_SIMULATOR
#error Do not support the simulator, please use the real iPhone Device.
#endif

#import "substrate.h"
#import <UIKit/UIkit.h>
#import <Foundation/Foundation.h>
#import "CaptainHook/CaptainHook.h"

#import "PushPackage.h"
#import "GJIMMessageModel.h"
#import "GJIMSessionService.h"
#import "GJIMMessageService.h"
#import "BDEncrypt.h"
#import "BDChatBasicCell.h"

#import "GJIMDBService.h"
#import "GJIMSessionToken.h"

CHDeclareClass(UITableViewCell);
CHDeclareClass(GJIMSessionService);


CHOptimizedMethod1(self, id, GJIMSessionService, p_handlePushPackage, PushPackage*, pkg) {
    switch (pkg.messageType) {
        case 55: // 撤回
        {
            NSLog(@"[BLUEDHOOK] %@ 撤回消息已被拦截。", pkg.name);
            // 获取原始消息，打 tag
            GJIMSessionToken *sessionToken = [objc_getClass("GJIMSessionToken") gji_sessionTokenWithId: pkg.sessionId type:2];
            [objc_getClass("GJIMDBService") gji_getMessagesWithToken:sessionToken complete:^(id data) {
                GJIMMessageModel *targetMsg;
                
                for (GJIMMessageModel *msg in data) {
                    if (msg.msgId == pkg.messageId) {
                        targetMsg = msg;
                        break;
                    }
                }
                
                if (targetMsg == nil) {
                    NSLog(@"[BLUEDHOOK] Warning: cannot find msgid %llu from %d in message service, canceled tagging.", pkg.messageId, pkg.from);
                    targetMsg = [data lastObject];
                    targetMsg.type = 1;
                    targetMsg.msgId = pkg.messageId;
                    targetMsg.sendTime = pkg.timestamp;
                    targetMsg.msgExtra = @{@"BLUED_HOOK_IS_RECALLED": @1};
                    targetMsg.content = @"对方撤回了一条消息，但已错过接收原始消息无法复原。";
                    [self addMessage:targetMsg];
                    return;
                }
                
                targetMsg.msgExtra = @{@"BLUED_HOOK_IS_RECALLED": @1};
                [self updateMessage:targetMsg];
            }];
            
            return nil;
        }
            break;
        case 24:
            pkg.messageType = 2;
            pkg.contents = [objc_getClass("BDEncrypt") decryptVideoUrl:pkg.contents];
            pkg.msgExtra = @{@"BLUEDHOOK_IS_SNAPIMG": @1};
            break;
        default:
            break;
    }
    
    return CHSuper1(GJIMSessionService, p_handlePushPackage, pkg);
}

CHOptimizedMethod0(self, id, UITableViewCell, contentView){
    NSString *cellClassName = [NSString stringWithFormat:@"%@", ((UIView*)self).class];
//    NSLog(@"-[UITableViewCell contentView]: %@", cellClassName);
    if (![cellClassName containsString:@"PrivateOther"]) {
        return CHSuper0(UITableViewCell, contentView);
    }
    
    UIView *contentView = CHSuper0(UITableViewCell, contentView);
    GJIMMessageModel *msg = [[(BDChatBasicCell*)self message] copy];
    if (msg == nil) {
        return contentView;
    }
    NSLog(@"handing msg type:%llu, msgID: %llu, msgContent: %@\nBLUEDHOOK_IS_SNAPIMG: %@, BLUED_HOOK_IS_RECALLED: %@", msg.type, msg.msgId, msg.content, [msg.msgExtra objectForKey:@"BLUEDHOOK_IS_SNAPIMG"], [msg.msgExtra objectForKey:@"BLUED_HOOK_IS_RECALLED"]);
    // 1: 普通文本消息
    // 2: 图片消息
    // 3: 语音消息
    // 6: 大表情
    // 24: 闪照
    // 渲染时如果检测到未处理闪照，如非推送的历史消息拉取
    if (msg.type == 24) {
        msg.type = 2;
        msg.content = [objc_getClass("BDEncrypt") decryptVideoUrl:msg.content];
        msg.msgExtra = @{@"BLUEDHOOK_IS_SNAPIMG": @1};
        GJIMSessionService * sessionService = [objc_getClass("GJIMSessionService") sharedInstance];
        [sessionService updateMessage:msg];
        return contentView;
    }
    
    NSInteger labelTag = 1069;
    
    
    CGFloat labelPosTop = contentView.frame.size.height-12;
    CGFloat labelPosLeft = [contentView subviews][2].frame.origin.x;
    
    switch (msg.type) {
        case 1:
            labelPosTop -= 8;
            labelPosLeft += 12;
            break;
        case 3:
            labelPosLeft += 12;
            break;
        default:
            break;
    }
    
    CGRect labelFrame = CGRectMake(labelPosLeft, labelPosTop, contentView.frame.size.width, 12);
    UILabel *label;
    UILabel *oldLabel = [self viewWithTag:labelTag];
    if (oldLabel == nil) {
        label = [[UILabel alloc] init];
    } else {
        label = oldLabel;
    }
    
    [label setFrame:labelFrame];
    
    NSArray *keys = [msg.msgExtra allKeys];
    if (msg.msgId == 0 || [keys count] == 0) {
        return contentView;
    }
    
    NSString *labelText = @"";
    if ([keys containsObject:@"BLUEDHOOK_IS_SNAPIMG"]) {
        labelText = @"该照片由闪照转换而成。";
    } else if([keys containsObject:@"BLUED_HOOK_IS_RECALLED"]) {
        labelText = @"对方尝试撤回此消息，已被阻止。";
        if ([msg.content containsString:@"burn-chatfiles"]) {
            labelText = @"该闪照已被对方撤回。";
        }
//    } else if ([keys containsObject:@"BLUED_HOOK_RECALLED_MISSED"]){
//        labelText = @"已错过接收原始消息。";
    }
    else {
//        return contentView;
//        labelText = [NSString stringWithFormat:@"%llu: %@", msg.msgId, msg.content];
    }


    [label setFont:[UIFont systemFontOfSize:9]];
    label.textColor = [UIColor grayColor];
    label.tag = labelTag;
    label.text = labelText;
    label.numberOfLines = 1;
    //label.backgroundColor = [UIColor colorWithRed:0 green:0 blue:0 alpha:0.1];
    [self addSubview:label];

//    NSLog(@"===================");
//    for (UIView *subview in [contentView subviews]) {
//        NSLog(@"%@", subview.class);
//    }
//    NSLog(@"===================");

    return contentView;
}



CHConstructor {
    @autoreleasepool {
        CHLoadLateClass(GJIMSessionService);
        CHClassHook1(GJIMSessionService, p_handlePushPackage);
        
        CHLoadLateClass(UITableViewCell);
        CHHook0(UITableViewCell, contentView);
    }

}
