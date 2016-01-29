//
//  WConfig.h
//  Wilddog
//
//  Created by junpengwang on 15/7/20.
//  Copyright (c) 2015年 Wilddog. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * Configuration object for Wilddog.  You can get the default WConfig object via
 * `[Wilddog defaultConfig]` and modify it.  You must make all changes to it before
 * you create your first Wilddog instance.
 */
@interface WConfig : NSObject

/**
 * By default the Wilddog client will keep data in memory while your application is running, but not
 * when it is restarted. By setting this value to YES, the data will be persisted to on-device (disk)
 * storage and will thus be available again when the app is restarted (even when there is no network
 * connectivity at that time). Note that this property must be set before creating your first Wilddog
 * reference and only needs to be called once per application.
 *
 * If your app uses Wilddog Authentication, the client will automatically persist the user's authentication
 * token across restarts, even without persistence enabled. But if the auth token expired while offline and
 * you've enabled persistence, the client will pause write operations until you successfully re-authenticate
 * (or explicitly unauthenticate) to prevent your writes from being sent unauthenticated and failing due to
 * security rules.
 */
@property (nonatomic) BOOL persistenceEnabled;

/**
 * By default Wilddog will use up to 10MB of disk space to cache data. If the cache grows beyond this size,
 * Wilddog will start removing data that hasn't been recently used. If you find that your application caches too
 * little or too much data, call this method to change the cache size. This property must be set before creating
 * your first Wilddog reference and only needs to be called once per application.
 *
 * Note that the specified cache size is only an approximation and the size on disk may temporarily exceed it
 * at times.
 */
@property (nonatomic) NSUInteger persistenceCacheSizeBytes;

/**
 *  设置所有被触发事件的队列。默认队列为主队列。
 */
@property (nonatomic, strong) dispatch_queue_t callbackQueue;

@end
