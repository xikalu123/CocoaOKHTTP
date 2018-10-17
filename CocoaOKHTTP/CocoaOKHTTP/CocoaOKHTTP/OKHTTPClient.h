//
//  OKHTTPClient.h
//  CocoaOKHTTP
//
//  Created by 陈宇亮 on 2018/10/17.
//  Copyright © 2018年 Mars. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OKHTTPCall.h"
#import "OKHTTPRequest.h"
#import "OKHTTPInterceptor.h"

NS_ASSUME_NONNULL_BEGIN

@class OKHTTPClientBuilder;

@interface OKHTTPClient : NSObject

@property (nonatomic, readonly) NSArray<id<OKHTTPInterceptorProtocol>>* interceptors;
@property (nonatomic, readonly) NSArray<id<OKHTTPInterceptorProtocol>>* networkInterceptors;
@property (nonatomic, readonly) NSString *name;

+ (instancetype)clientWithBuilder:(void (^)(OKHTTPClientBuilder *builder))block;

- (OKHTTPRequest *)rquestWithBuilder:(void (^)(OKHTTPRequestBuilder *))block;

- (nullable id<OKHTTPCallProtocol>)makeCall:(OKHTTPRequest *)request;

@end

@interface OKHTTPClient(Extends)

+ (instancetype)client;

- (id<OKHTTPCallProtocol>)asynCall:(OKHTTPRequest*)request;


@end


@interface OKHTTPClientBuilder : NSObject

- (nullable OKHTTPClient*)build;

- (void)addInterceptors:(NSArray<id<OKHTTPInterceptorProtocol>> *)array;
- (void)addNetworkInerceptors:(NSArray<id<OKHTTPInterceptorProtocol>> *)array;

@end

NS_ASSUME_NONNULL_END
