//
//  OKHTTPCall.h
//  CocoaOKHTTP
//
//  Created by 陈宇亮 on 2018/10/17.
//  Copyright © 2018年 Mars. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OKHTTPRequest.h"
#import "OKHTTPCallback.h"

NS_ASSUME_NONNULL_BEGIN

@class OKHTTPClient;

@protocol OKHTTPCallProtocol <NSObject>

- (void)cancel;

- (BOOL)isExecuted;

- (BOOL)isCanceled;

- (instancetype)clone;

@end

@interface OKHTTPRealCall : NSObject <OKHTTPCallProtocol>

+ (instancetype)realCallWithClient:(OKHTTPClient *)client originRequest:(OKHTTPRequest *)request;

@end

@interface OKHTTPAsyncCall : NSOperation

+ (instancetype)asyncCall:(OKHTTPRealCall *)that responseCallBack:(id<OKHTTPCallbackProtocol>)cb;

@property (nonatomic,assign) NSTimeInterval enqueueTimestamp;

@end

@interface OKHTTPAsyncCallV2 : NSThread

+ (instancetype)asyncCall:(OKHTTPRealCall *)that responseCallBack:(nonnull id<OKHTTPCallbackProtocol>)cb;

@property (nonatomic,assign) NSTimeInterval enqueueTimestamp;

@end

NS_ASSUME_NONNULL_END
