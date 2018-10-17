//
//  OKHTTPClient.m
//  CocoaOKHTTP
//
//  Created by 陈宇亮 on 2018/10/17.
//  Copyright © 2018年 Mars. All rights reserved.
//

#import "OKHTTPClient.h"
#import "OKHTTPDispatcher.h"

@interface OKHTTPClient()

@property (nonatomic, strong) NSArray<id<OKHTTPInterceptorProtocol>>* interceptors;
@property (nonatomic, strong) NSArray<id<OKHTTPInterceptorProtocol>>* networkInterceptors;
@property (nonatomic, strong) OKHTTPDispatcher *dispatcher;
@property (nonatomic, copy)   NSString *name;
@end

@implementation OKHTTPClient

+ (instancetype)clientWithBuilder:(void (^)(OKHTTPClientBuilder * _Nonnull))block
{
    OKHTTPClientBuilder *builder = [OKHTTPClientBuilder new];
    block(builder);
    return [builder build];
}

- (OKHTTPRequest *)rquestWithBuilder:(void (^)(OKHTTPRequestBuilder * _Nonnull))block
{
    OKHTTPRequestBuilder *builder = [OKHTTPRequestBuilder new];
    block(builder);
    return [builder build];
}

- (id<OKHTTPCallProtocol>)makeCall:(OKHTTPRequest *)request
{
    NSError *error;
    OKHTTPRealCall *call;
    if ([request isValid:&error]) {
        call = [OKHTTPRealCall realCallWithClient:self originRequest:request];
    }
    else{
        NSLog(@"request invalid");
    }
    return call;
}

@end


@interface OKHTTPClientBuilder()

@property (nonatomic, strong) NSMutableArray<id<OKHTTPInterceptorProtocol>> *interceptors;
@property (nonatomic, strong) NSMutableArray<id<OKHTTPInterceptorProtocol>> *networkInterceptors;
@property (nonatomic, copy) NSString *name;

@end

@implementation OKHTTPClientBuilder

- (instancetype)init{
    if (self = [super init]) {
        _interceptors = [NSMutableArray new];
        _networkInterceptors = [NSMutableArray new];
        
    }
    return self;
}

- (OKHTTPClient *)build
{
    OKHTTPClient *client = [OKHTTPClient new];
    client.name = self.name;
    client.interceptors = self.interceptors;
    client.networkInterceptors = self.networkInterceptors;
    client.dispatcher = [OKHTTPDispatcher new];
    
    return client;
}

- (void)addInterceptors:(NSArray<id<OKHTTPInterceptorProtocol>> *)array
{
    [self.interceptors addObjectsFromArray:array];
}

- (void)addNetworkInerceptors:(NSArray<id<OKHTTPInterceptorProtocol>> *)array
{
    [self.networkInterceptors addObjectsFromArray:array];
}



@end
