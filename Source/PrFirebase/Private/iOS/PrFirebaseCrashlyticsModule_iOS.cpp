// Copyright 2020-2024 Nikolay Prudnikov. All Rights Reserved.

#include "iOS/PrFirebaseCrashlyticsModule_iOS.h"

#include "PrFirebaseDefines.h"

#if WITH_FIREBASE_CRASHLYTICS && PLATFORM_IOS
#import <Firebase.h>

void UPrFirebaseCrashlyticsModule_iOS::Crash()
{
	UE_LOG(LogFirebase, Fatal, TEXT("Crash"));
}

void UPrFirebaseCrashlyticsModule_iOS::SetUserIdentifier(const FString& UserIdentifier)
{
	[[FIRCrashlytics crashlytics] setUserID:UserIdentifier.GetNSString()];
}

void UPrFirebaseCrashlyticsModule_iOS::WriteLog(const FString& Log)
{
	[[FIRCrashlytics crashlytics] log:Log.GetNSString()];
}

void UPrFirebaseCrashlyticsModule_iOS::WriteError(const FString& Log, int32 Code, const TMap<FString, FString>& UserInfo)
{
	NSDictionary<NSErrorUserInfoKey, id>* UserInfoDict = nil;
	if (UserInfo.Num() > 0)
	{
		UserInfoDict = [NSMutableDictionary dictionaryWithCapacity:UserInfo.Num()];
		for (const auto& UserInfoPair : UserInfo)
		{
			[UserInfoDict setValue:[NSString stringWithFString:UserInfoPair.Value] forKey:[NSString stringWithFString:UserInfoPair.Key]];
		}
	}

	NSError* error = [NSError errorWithDomain:Log.GetNSString() code:Code userInfo:UserInfoDict];
	[[FIRCrashlytics crashlytics] recordError:error];
}

void UPrFirebaseCrashlyticsModule_iOS::AddAttribute(const FString& Key, const FString& Value)
{
	[[FIRCrashlytics crashlytics] setCustomValue:Value.GetNSString() forKey:Key.GetNSString()];
}

void UPrFirebaseCrashlyticsModule_iOS::Initialize_AnyThread()
{
	[[FIRCrashlytics crashlytics] setCrashlyticsCollectionEnabled:YES];
	CatchEngineLogs();
}

#endif // WITH_FIREBASE_CRASHLYTICS && PLATFORM_IOS
