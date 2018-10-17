//
//  OKHTTPCall.m
//  CocoaOKHTTP
//
//  Created by 陈宇亮 on 2018/10/17.
//  Copyright © 2018年 Mars. All rights reserved.
//

#import "OKHTTPCall.h"
#import "OKHTTPInterceptor.h"

@interface OKHTTPRealCall()

@property (nonatomic, strong) OKHTTPClient *client;
@property (nonatomic, strong) OKHTTPRequest *originRequest;
@property (nonatomic, strong) NSArray<OKHTTPInterceptorProtocol> *interceptors;

@end

@implementation OKHTTPRealCall

+ (instancetype)realCallWithClient:(OKHTTPClient *)client originRequest:(OKHTTPRequest *)request
{
    OKHTTPRealCall *call = [OKHTTPRealCall new];
    call.client = client;
    call.originRequest = request;
    return call;
}

#pragma mark protocol

@end


@interface OKHTTPAsyncCall()

@end

@implementation OKHTTPAsyncCall

@end


@interface OKHTTPAsyncCallV2()

@end

@implementation OKHTTPAsyncCallV2

@end
