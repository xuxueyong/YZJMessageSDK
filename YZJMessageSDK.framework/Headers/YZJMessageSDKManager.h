//
//  YZJMessageSDKManager.h
//
//  Created by hour on 2019/5/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YZJMessageSDKConfig: NSObject

// 基础域名
@property (nonatomic, strong, nonnull) NSString *baserUrl;
@property (nonatomic, strong, nonnull) NSString *baserImgUrl;

/// mars
@property (nonatomic, strong, nonnull) NSString *pubKey;
@property (nonatomic, strong, nonnull) NSString *longLinkAddress;
@property (nonatomic, assign) unsigned short longLinkPort;
@property (nonatomic, strong, nonnull) NSString *shortLinkAddress;
@property (nonatomic, assign) unsigned short shortLinkPort;

// UI 配置
@property (nonatomic, strong, nullable) UIImage *groupListNavLeftIconImage; // 群组列表导航栏左侧头像图片
@property (nonatomic, strong, nullable) NSString *groupListNavTitle;        // 群组列表导航栏标题，默认："消息"

//@property (nonatomic, strong, nonnull) NSString *openToken;
//@property (nonatomic, strong, nonnull) NSString *userAgent;
//@property (nonatomic, strong, nonnull) NSString *clientId;
@end

typedef void(^YZJTimelineBlock)(void);

@interface YZJTimelineConfig: NSObject

/// 标题
@property (nonatomic, strong, nonnull) NSString *titleName;

/// 左边按钮的图片 和 点击操作
@property (nonatomic, strong, nonnull) UIImage *leftImage;
@property (nonatomic, copy, nonnull) YZJTimelineBlock leftBlock;

@end


@protocol YZJMessageSDKManagerDelegate <NSObject>

/// 未读数变化时会调用
- (void)unreadCountChanged:(NSUInteger)unreadCount;

/// 导航栏左侧头像点击事件
@optional
- (void)onGroupListLeftIconTap;

@end

@interface YZJMessageSDKManager : NSObject


+ (instancetype)shared;

/// 初始参数的配置 只调用一次
- (void)setupWithConfig:(YZJMessageSDKConfig *)config
               delegate:(id<YZJMessageSDKManagerDelegate>)delegate;

/// 用户登录，登录成功后会执行数据初始化操作，建立长连
- (void)loginWithUsername:(NSString *)username password:(NSString *)password;

/// 用户退出登录
- (void)logout;

- (YZJMessageSDKConfig *)config;

- (id<YZJMessageSDKManagerDelegate>)delegate;

/// 消息列表 view controller 注意是：UINavigationController
- (UINavigationController *)timelineVC;

/// 收到推送后 打开推送消息
//- (void)openMsgWithMsgId:(NSString *)msgId;




@end


NS_ASSUME_NONNULL_END
