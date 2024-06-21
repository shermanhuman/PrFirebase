![GitHub](https://img.shields.io/github/license/nprudnikov/PrFirebase)

# PrFirebase

[Firebase](https://firebase.google.com/) SDK integration for [Unreal Engine 4](https://www.unrealengine.com/). Kindly supported by [ufna](https://github.com/ufna).

Implemented SDK versions:
* Android: com.google.firebase:firebase-bom:26.1.1, com.google.gms:google-services:4.3.4
* [Firebase iOS 7.1.0](https://github.com/firebase/firebase-ios-sdk/releases/tag/CocoaPods-7.1.0)

Primary supported modules:
* Analytics
* Crashlytics
* Performance
* Remote Config

Planned:
* Functions

Current version: **1.0 R 1** (UE 4.26)


![SCREENSHOT](SCREENSHOT.jpg)

## Installation

### Prerequisites
AndroidX support is required to run Firebase on Android platform. If your project is not configured yet, take a look at [ufna/AndroidX-UE4](https://github.com/ufna/AndroidX-UE4) plugin - just add it and job is done.

### Install steps
1. Clone [ufna/AndroidX-UE4](https://github.com/ufna/AndroidX-UE4) to your   Unreal project Plugins directory.  If you don't have a Plugins directory create one.  Example: `..\Documents\Unreal Projects\My Project\Plugins`.
1. Clone [this repo](https://github.com/nprudnikov/PrFirebase) to the Plugins directory as well.  You should now have the `AndroidX-UE4` and `PrFirebase` folders under plugins with source code for both projects.
1. Compile the plugins.  Unreal will do this automatically when you open your project, so a quick way to do this is to open and close your project in Unreal engine.
1. Install your Firebase config files.  Create a `Firebase` folder in your `Config` directory.  Example: `..\Documents\Unreal Projects\My Project\Config\Firebase` and then place your Firebase `google-services.json` (for Android) and `GoogleService-Info.plist` (iOS) in there.  *Optionally you can specify the location of these files in the PrFirebase config.*
1. Configure settings.  These are found in your Unreal Project Settings: __Edit > Project Settings > PrFirebase__.    
