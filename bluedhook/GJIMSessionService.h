//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

//#import "NSObject.h"

//#import "GJIMDelegate.h"

@class GJIMMultiCastDelegate, NSDate, NSMutableDictionary, NSString;

@interface GJIMSessionService
{
    GJIMMultiCastDelegate *_multiDelegate;
//    id <GJIMSessionServiceDelegate> _gji_multiDelegate;
    NSMutableDictionary *_sessionDict;
    NSMutableDictionary *_messageServiceDict;
    NSMutableDictionary *_messageIdsDict;
    NSDate *_soundDate;
}

+ (_Bool)isInternational;
+ (void)releaseSharedInstance;
+ (id)sharedInstance;
//- (void).cxx_destruct;
@property(retain, nonatomic) NSDate *soundDate; // @synthesize soundDate=_soundDate;
@property(retain, nonatomic) NSMutableDictionary *messageIdsDict; // @synthesize messageIdsDict=_messageIdsDict;
@property(retain, nonatomic) NSMutableDictionary *messageServiceDict; // @synthesize messageServiceDict=_messageServiceDict;
@property(retain, nonatomic) NSMutableDictionary *sessionDict; // @synthesize sessionDict=_sessionDict;
//@property(retain, nonatomic) id <GJIMSessionServiceDelegate> gji_multiDelegate; // @synthesize gji_multiDelegate=_gji_multiDelegate;
- (void)updateNewUserMessage:(id)arg1;
- (unsigned int)getCardCount:(unsigned int)arg1;
- (unsigned int)getGiftCount:(unsigned int)arg1;
- (void)addGiftUnreadCount:(id)arg1 giftType:(int)arg2;
- (id)sortSessions:(id)arg1;
//- (void)getTopCount:(CDUnknownBlockType)arg1;
- (void)syncNewMessage;
- (void)gji_authed:(id)arg1;
- (void)gji_responsePushPackage:(id)arg1;
- (_Bool)p_kickedSelf:(id)arg1;
- (void)p_internationalUpdateSessionIfNeed:(id)arg1;
- (void)p_unIternationalUpdateSessionIfNeed:(id)arg1;
- (void)p_updateSessionIfNeed:(id)arg1;
- (int)p_getStopTime:(int)arg1 startTime:(int)arg2;
- (_Bool)p_isTopGiftMessageTopTime:(int)arg1;
- (id)p_handlePushPackage:(id)arg1;
- (void)p_fetchSyncMessagesWithType:(unsigned long long)arg1 syncLocalId:(unsigned int)arg2;
- (void)p_updateBoxSessionForFollowWith:(id)arg1;
- (id)p_getBoxSessionMessageContent;
- (void)p_updatBoxSession;
- (int)p_newFansUnreadMessagesCount;
- (unsigned int)p_getBoxSessionUnreadCountWith:(id)arg1;
- (id)p_internationalUnreadMessagesCountDict;
- (id)p_unreadMessagesCountDict;
- (void)p_notifyDelegate;
- (void)p_clearAllBoxSession;
- (id)p_InternationalSortSessions:(id)arg1 isFriend:(_Bool)arg2;
- (id)p_sortSessions:(id)arg1;
- (id)sortSessionsByTime:(id)arg1;
//- (void)sortAndFlatOfficialSessions:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (id)p_updateSessionWithMessage:(id)arg1;
- (_Bool)p_isJoinGroupMessage:(id)arg1 session:(id)arg2;
- (id)p_sessionWithMessage:(id)arg1;
- (void)p_setSessions:(id)arg1;
- (void)p_setSession:(id)arg1;
- (void)syncLastMessageWithSessionType:(unsigned char)arg1 sessionId:(unsigned int)arg2;
- (void)updateSessionStatus:(id)arg1;
- (void)updateUnreadMessagesCount_international;
- (void)updateUnreadMessagesCount;
- (void)removeMessageServiceWithToken:(id)arg1;
- (void)addMessageService:(id)arg1;
//- (void)isActiveWithToken:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (_Bool)isActiveMessage:(id)arg1;
- (id)messageWithToken:(id)arg1 messageId:(unsigned long long)arg2;
- (void)updateMessageWithoutDelegate:(id)arg1;
- (void)deleteMessage:(id)arg1;
- (void)updateMessage:(id)arg1;
- (void)addMessages:(id)arg1;
- (void)addMessage:(id)arg1;
//- (void)checkSessionsIfEmpty:(CDUnknownBlockType)arg1;
- (id)sessionsFromPrivate;
- (id)sessionsFromPrivate_Internation;
- (id)sessionsFromPrivateAndGroup;
//- (void)sessionWithToken:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (id)sessionWithToken:(id)arg1;
//- (void)latestMessageIdWithToken:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (unsigned long long)latestMessageIdWithToken:(id)arg1;
- (void)clearMemory;
- (void)clearAllSessionsUnreadCountAndContent;
- (void)clearAllSessionsUnreadCount;
- (void)clearSessionWithToken_International:(id)arg1;
- (void)clearAllBoxSessionsAndMessages_Internation;
- (void)clearSessionAndMessageWithToken:(id)arg1;
- (void)clearSessionWithToken:(id)arg1;
- (void)clearAllMessages;
- (void)clearAllSessions;
- (void)clearAtInfoWithToken:(id)arg1;
- (void)syncSetMaxHasReadMsgIdWithToken:(id)arg1;
- (void)setMaxHasReadMsgIdWithToken:(id)arg1;
- (void)setMessageType:(unsigned long long)arg1 token:(id)arg2;
- (void)p_deleteBoxSession;
- (void)setTotoalMoney:(double)arg1 token:(id)arg2;
- (void)setFriendStatus:(int)arg1 token:(id)arg2;
- (void)setInternationalVbadge:(int)arg1 token:(id)arg2;
- (void)setInternationalFaceStatus:(int)arg1 token:(id)arg2;
- (void)setSessionName:(id)arg1 token:(id)arg2;
- (void)setAvatar:(id)arg1 token:(id)arg2;
- (void)setStatus:(unsigned char)arg1 token:(id)arg2;
- (void)setDraft:(id)arg1 token:(id)arg2;
- (void)setDistance:(id)arg1 byToken:(id)arg2;
- (void)setSecretLookStatus:(unsigned char)arg1 byToken:(id)arg2;
- (void)setInternationalVipLook:(unsigned int)arg1 byToken:(id)arg2;
- (void)setInternationalVipGrade:(unsigned int)arg1 vipAnnual:(unsigned int)arg2 byToken:(id)arg3;
- (void)setInternationalVipGrade:(unsigned int)arg1 byToken:(id)arg2;
- (void)setVipGrade:(unsigned int)arg1 vipAnnual:(unsigned int)arg2 vipExpLvl:(unsigned int)arg3 vipLook:(unsigned int)arg4 byToken:(id)arg5;
- (void)setNoteName:(id)arg1 token:(id)arg2;
- (void)setMsgExtra:(id)arg1 token:(id)arg2;
- (void)setTop:(_Bool)arg1 token:(id)arg2;
- (void)setGroupRole:(unsigned char)arg1 sessionToken:(id)arg2;
- (void)setGroupStatus:(unsigned char)arg1 sessionToken:(id)arg2;
- (void)setSuper:(unsigned char)arg1 sessionToken:(id)arg2;
- (void)setQuiet:(int)arg1 token:(id)arg2;
- (void)setFollow:(_Bool)arg1 token:(id)arg2;
- (void)resortSessionsForBoxStatus;
//- (void)fetchBoxSessions_International:(CDUnknownBlockType)arg1;
//- (void)fetchSessions_International:(CDUnknownBlockType)arg1;
//- (void)fetchSessions_ChatKit:(CDUnknownBlockType)arg1;
//- (void)fetchSessions:(CDUnknownBlockType)arg1;
- (void)addDelegate:(id)arg1;
- (id)init;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

