#include <cstring>
#include <string>
#include <ctime>
#include <android/native_window_jni.h>
#include "Tools/android_native_app_glue.h"
#include <android/log.h>
#include "UE_SDK/SDK.hpp"
#include "Tools/GlossHook/Gloss.h"
using namespace SDK;
using namespace std;
#include "Tools/include.h"
#include "Oxorany/oxorany.cpp"
#include "shadowhook/shadowhook.h"
#include "Substrate/SubstrateHook.h"
#include "Includes/Macros.h"
#include "Includes/Logger.h"
#include "Includes/Utils.h"
#include <curl/curl.h>

#define GNames_Offset 0x78cfc08
#define GEngine_Offset 0xde24c70 //ULocalPlayer
#define GEngine_Offset 0xde49de8 //UEngine
#define GUObject_Offset 0x9999990
#define GetActorArray_Offset 0x994dc6c
#define Process_Event_Offset 0x7b326e4 
#define GNativeAndroidApp_Offset 0xd876fd0
#define Actors_Offset 0xa0

static bool IsOpen = false;
static volatile bool 辅助验证1 = false;
static volatile int 辅助验证2 = 0;
static volatile uint32_t 随机种子 = 0;
volatile int 干扰变量[100] = {0};
 bool 防拉4;
 bool 防封;

android_app* g_App = 0;
ANativeWindow* ANativeWindow_p;
void android_main(struct android_app* state) {
    std::srand(std::time(nullptr));
    随机种子 = std::rand();
    for (int i = 0; i < 100; i++) {
        干扰变量[i] = std::rand() % 1000;
    }
}

#include "ZeroGui/ZeroGUI.h"

static char s[64];
static volatile bool 真实验证 = false;
static volatile bool* p验证 = &真实验证; // 通过指针间接访问
static char BQAQSQEQ[128] = {"OdgostKJfqL3W0mwNc74pBEZFXDCIvPzVxRYnAMlbUhGT5Srakjy2+uH618/ieQ9"};
char* appkey = OBFUSCATE("ced929006db1245a4132769a068c7c50");
char* 登录调用码 = OBFUSCATE("D1D8C23350AACCCC");
char* 公告调用码 = OBFUSCATE("5B87411F71F942C4");
char* 解绑调用码 = OBFUSCATE("A71737945C815D89");
#include "Tools/T3/T3验证.h"
#define SLEEP_TIME 1000LL / 120LL

TNameEntryArray* GetGNames(DERO CHEATS)
{
	return ((TNameEntryArray * (DERO)()) (UE4 + GITHUB))();
}

void CheckCardKeyAndExpiration() {
    if (到期时间 == nullptr || strlen(到期时间) == 0) {
        exit(-1);  // 如果到期时间为空，直接退出
    }
}

bool 检测调试器() {
    char buffer[1024];
    FILE* status = fopen("/proc/self/status", "r");
    if (status) {
        while (fgets(buffer, sizeof(buffer), status)) {
            if (strstr(buffer, "TracerPid:") != nullptr) {
                int tracer_pid = atoi(buffer + 10);
                fclose(status);
                return (tracer_pid != 0);
            }
        }
        fclose(status);
    }
    return false;
}







int 跳转(const char* url)
{
JavaVM* java_vm = g_App->activity->vm;
JNIEnv* java_env = NULL;
jint jni_return = java_vm->GetEnv((void**)&java_env, JNI_VERSION_1_6);
if (jni_return == JNI_ERR)
return -1;
jni_return = java_vm->AttachCurrentThread(&java_env, NULL);
if (jni_return != JNI_OK)
return -2;
jclass native_activity_clazz = java_env->GetObjectClass(g_App->activity->clazz);
if (native_activity_clazz == NULL)
return -3;
jmethodID method_id = java_env->GetMethodID(native_activity_clazz, "AndroidThunkJava_LaunchURL", "(Ljava/lang/String;)V");
if (method_id == NULL)
return -4;
jstring retStr = java_env->NewStringUTF(url);
java_env->CallVoidMethod(g_App->activity->clazz, method_id, retStr);
jni_return = java_vm->DetachCurrentThread();
if (jni_return != JNI_OK)
return -5;
return 0;
}



std::string getClipboardText() {
    if (!g_App)
        return "";

    auto activity = g_App->activity;
    if (!activity)
        return "";

    auto vm = activity->vm;
    if (!vm)
        return "";

    auto object = activity->clazz;
    if (!object)
        return "";

    std::string result;

    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);
    {
        auto ContextClass = env->FindClass("android/content/Context");
        auto getSystemServiceMethod = env->GetMethodID(ContextClass, "getSystemService", "(Ljava/lang/String;)Ljava/lang/Object;");

        auto str = env->NewStringUTF("clipboard");
        auto clipboardManager = env->CallObjectMethod(object, getSystemServiceMethod, str);
        env->DeleteLocalRef(str);

        auto ClipboardManagerClass = env->FindClass("android/content/ClipboardManager");
        auto getText = env->GetMethodID(ClipboardManagerClass, "getText", "()Ljava/lang/CharSequence;");

        auto CharSequenceClass = env->FindClass("java/lang/CharSequence");
        auto toStringMethod = env->GetMethodID(CharSequenceClass, "toString", "()Ljava/lang/String;");

        auto text = env->CallObjectMethod(clipboardManager, getText);
        if (text) {
            str = (jstring) env->CallObjectMethod(text, toStringMethod);
            result = env->GetStringUTFChars(str, 0);
            env->DeleteLocalRef(str);
            env->DeleteLocalRef(text);
        }

        env->DeleteLocalRef(CharSequenceClass);
        env->DeleteLocalRef(ClipboardManagerClass);
        env->DeleteLocalRef(clipboardManager);
        env->DeleteLocalRef(ContextClass);
    }
    vm->DetachCurrentThread();

    return result;
}

const char *GetDeviceModel(JNIEnv *env) {
    jclass buildClass = env->FindClass(/*android/os/Build*/ StrEnc("m5I{GKGWBP-VOxkA", "\x0C\x5B\x2D\x09\x28\x22\x23\x78\x2D\x23\x02\x14\x3A\x11\x07\x25", 16).c_str());
    jfieldID modelId = env->GetStaticFieldID(buildClass, /*MODEL*/ StrEnc("|}[q:", "\x31\x32\x1F\x34\x76", 5).c_str(), /*Ljava/lang/String;*/ StrEnc(".D:C:ETZ1O-Ib&^h.Y", "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62", 18).c_str());

    auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceBrand(JNIEnv *env) {
    jclass buildClass = env->FindClass(/*android/os/Build*/ StrEnc("0iW=2^>0zTRB!B90", "\x51\x07\x33\x4F\x5D\x37\x5A\x1F\x15\x27\x7D\x00\x54\x2B\x55\x54", 16).c_str());
    jfieldID modelId = env->GetStaticFieldID(buildClass, /*BRAND*/ StrEnc("@{[FP", "\x02\x29\x1A\x08\x14", 5).c_str(), /*Ljava/lang/String;*/ StrEnc(".D:C:ETZ1O-Ib&^h.Y", "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62", 18).c_str());

    auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetAndroidID(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass(/*android/content/Context*/ StrEnc("`L+&0^[S+-:J^$,r9q92(as", "\x01\x22\x4F\x54\x5F\x37\x3F\x7C\x48\x42\x54\x3E\x3B\x4A\x58\x5D\x7A\x1E\x57\x46\x4D\x19\x07", 23).c_str());
    jmethodID getContentResolverMethod = env->GetMethodID(contextClass, /*getContentResolver*/ StrEnc("E8X\\7r7ys_Q%JS+L+~", "\x22\x5D\x2C\x1F\x58\x1C\x43\x1C\x1D\x2B\x03\x40\x39\x3C\x47\x3A\x4E\x0C", 18).c_str(), /*()Landroid/content/ContentResolver;*/ StrEnc("8^QKmj< }5D:9q7f.BXkef]A*GYLNg}B!/L", "\x10\x77\x1D\x2A\x03\x0E\x4E\x4F\x14\x51\x6B\x59\x56\x1F\x43\x03\x40\x36\x77\x28\x0A\x08\x29\x24\x44\x33\x0B\x29\x3D\x08\x11\x34\x44\x5D\x77", 35).c_str());
    jclass settingSecureClass = env->FindClass(/*android/provider/Settings$Secure*/ StrEnc("T1yw^BCF^af&dB_@Raf}\\FS,zT~L(3Z\"", "\x35\x5F\x1D\x05\x31\x2B\x27\x69\x2E\x13\x09\x50\x0D\x26\x3A\x32\x7D\x32\x03\x09\x28\x2F\x3D\x4B\x09\x70\x2D\x29\x4B\x46\x28\x47", 32).c_str());
    jmethodID getStringMethod = env->GetStaticMethodID(settingSecureClass, /*getString*/ StrEnc("e<F*J5c0Y", "\x02\x59\x32\x79\x3E\x47\x0A\x5E\x3E", 9).c_str(), /*(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;*/ StrEnc("$6*%R*!XO\"m18o,0S!*`uI$IW)l_/_knSdlRiO1T`2sH|Ouy__^}%Y)JsQ:-\"(2_^-$i{?H", "\x0C\x7A\x4B\x4B\x36\x58\x4E\x31\x2B\x0D\x0E\x5E\x56\x1B\x49\x5E\x27\x0E\x69\x0F\x1B\x3D\x41\x27\x23\x7B\x09\x2C\x40\x33\x1D\x0B\x21\x5F\x20\x38\x08\x39\x50\x7B\x0C\x53\x1D\x2F\x53\x1C\x01\x0B\x36\x31\x39\x46\x0C\x15\x43\x2B\x05\x30\x15\x41\x43\x46\x55\x70\x0D\x59\x56\x00\x15\x58\x73", 71).c_str());

    auto obj = env->CallObjectMethod(context, getContentResolverMethod);
    auto str = (jstring) env->CallStaticObjectMethod(settingSecureClass, getStringMethod, obj, env->NewStringUTF(/*android_id*/ StrEnc("ujHO)8OfOE", "\x14\x04\x2C\x3D\x46\x51\x2B\x39\x26\x21", 10).c_str()));
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceUniqueIdentifier(JNIEnv *env, const char *uuid) {
    jclass uuidClass = env->FindClass(/*java/util/UUID*/ StrEnc("B/TxJ=3BZ_]SFx", "\x28\x4E\x22\x19\x65\x48\x47\x2B\x36\x70\x08\x06\x0F\x3C", 14).c_str());

    auto len = strlen(uuid);

    jbyteArray myJByteArray = env->NewByteArray(len);
    env->SetByteArrayRegion(myJByteArray, 0, len, (jbyte *) uuid);

    jmethodID nameUUIDFromBytesMethod = env->GetStaticMethodID(uuidClass, /*nameUUIDFromBytes*/ StrEnc("P6LV|'0#A+zQmoat,", "\x3E\x57\x21\x33\x29\x72\x79\x67\x07\x59\x15\x3C\x2F\x16\x15\x11\x5F", 17).c_str(), /*([B)Ljava/util/UUID;*/ StrEnc("sW[\"Q[W3,7@H.vT0) xB", "\x5B\x0C\x19\x0B\x1D\x31\x36\x45\x4D\x18\x35\x3C\x47\x1A\x7B\x65\x7C\x69\x3C\x79", 20).c_str());
    jmethodID toStringMethod = env->GetMethodID(uuidClass, /*toString*/ StrEnc("2~5292eW", "\x46\x11\x66\x46\x4B\x5B\x0B\x30", 8).c_str(), /*()Ljava/lang/String;*/ StrEnc("P$BMc' #j?<:myTh_*h0", "\x78\x0D\x0E\x27\x02\x51\x41\x0C\x06\x5E\x52\x5D\x42\x2A\x20\x1A\x36\x44\x0F\x0B", 20).c_str());

    auto obj = env->CallStaticObjectMethod(uuidClass, nameUUIDFromBytesMethod, myJByteArray);
    auto str = (jstring) env->CallObjectMethod(obj, toStringMethod);
    return env->GetStringUTFChars(str, 0);
}

std::string xorString(const std::string& input, char key) {
    std::string output = input;
    for (size_t i = 0; i < input.length(); ++i) {
        output[i] = input[i] ^ key;
    }
    return output;
}

char *提示;
static bool 错误提示 = false;
char *公告 = httppost(OBFUSCATE("w.t3data.net"),公告调用码, "");

std::string 登录(const char *user_key) {
    if (!g_App)
        return OBFUSCATE("内部错误");
    auto activity = g_App->activity;
    if (!activity)
        return OBFUSCATE("内部错误");

    auto vm = activity->vm;
    if (!vm)
        return OBFUSCATE("内部错误");

    auto object = activity->clazz;
    if (!object)
        return OBFUSCATE("内部错误");

    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);
    std::string hwid = user_key;
    
    hwid += GetAndroidID(env, object);
    hwid += GetDeviceModel(env);
    hwid += GetDeviceBrand(env);
    std::string UUID = getHEX(加64(GetAndroidID(env, object)));
    vm->DetachCurrentThread();
    std::string errMsg;
    
    //时间戳效验
    time_t ti = time(NULL);
    static char sj[13];
    获取时间戳(sj);
    std::string sjc = getHEX(加64(sj));
    
    //单码签名校验
    char sign2[256];
    sprintf(sign2, OBFUSCATE("kami=%s&imei=%s&t=%s&%s"), getHEX(加64(user_key)), UUID.c_str(), sjc.c_str(), appkey);
    char sign2md5[32] = { 0 };
    获取MD5(sign2, sign2md5);
    std::string sign22 = getHEX(加64(sign2md5));
    
    char 整[4096];
    sprintf(整,OBFUSCATE("kami=%s&imei=%s&t=%s&s=%s"), getHEX(加64(user_key)), UUID.c_str(), sjc.c_str(), sign22.c_str());
    char *内容 = NULL;
    char *数据 = httppost(OBFUSCATE("w.t3data.net"),登录调用码, 整);
    内容 = 解64(数据);
    if (strncmp(内容, OBFUSCATE("登录成功:16384;"), 12) == 0)
    {
        char *卡密ID = strstrstr(内容, OBFUSCATE("卡密ID:"), ";");
        到期时间 = strstrstr(内容, OBFUSCATE("到期时间:"), ";");
        CheckCardKeyAndExpiration();
        char *到期时间 = strstrstr(内容, OBFUSCATE("当前时间戳:"), ";");
        char *当前时间 = strstrstr(内容, OBFUSCATE("当前时间:"), ";");
        char *效验密钥 = strstrstr(内容, OBFUSCATE("效验密钥"), ";");
        //获取时间戳(sj);
        long vs1 = (long)atoll(sj);
        long vs2 = (long)atoll(当前时间);
        if ((vs1 - vs2) < 18)
        {
            真实验证 = true;
            登录验证 = true;        
            // --- 新增关联变量设置 ---
            辅助验证1 = true;                     // 设置辅助验证变量1
            辅助验证2 = 随机种子 ^ 0x12345678;    // 动态绑定随机种子
            // ----------------------
        } else {
            登录验证 = false;
            错误提示 = true;
            提示 = OBFUSCATE("时间戳效验失败");
        }
    }
    else
    {   
        错误提示 = true;
        提示 = 内容;
    }
    return "OK";
}
std::string Unbind(const char *user_key) {
    char 解绑整[256];
    sprintf(解绑整,OBFUSCATE("kami=%s"), user_key);
    char *解绑数据 = httppost(OBFUSCATE("w.t3data.net"),解绑调用码, 解绑整);
    错误提示 = true;
    提示 = 解绑数据;
    return "OK";
}


void* LoadFont(void*)
{
	while (!tslFont || !robotoFont)
	{
		tslFont = UObject::FindObject<UFont>(OBFUSCATE("Font TSLFont.TSLFont"));
		robotoFont = UObject::FindObject<UFont>(OBFUSCATE("Font Roboto.Roboto"));
		sleep(1);
	}
	return 0;
}

bool isInsideFOV(int x, int y) {
	int circle_x = screenWidth / 2;
	int circle_y = screenHeight / 2;
	int rad = (int)Settings.Aim.fovsize;
	return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}

#define W2S(w, s) UGameplayStatics::ProjectWorldToScreen(g_PlayerController, w, true, s)


auto Preferredhead(){
ASTExtraPlayerCharacter *result = 0;
float max = std::numeric_limits<float>::infinity();
auto Actors = GetActors();
auto localPlayer = g_LocalPlayer;
auto localPlayerController = g_PlayerController;
if (localPlayer) {
std::vector<ASTExtraPlayerCharacter *> PlayerCharacter;
GetAllActors(PlayerCharacter);
for (auto actor = PlayerCharacter.begin(); actor != PlayerCharacter.end(); actor++)
{					
auto Player = *actor;						
if (Player->PlayerKey == localPlayer->PlayerKey)
continue;
if (Player->TeamID == localPlayer->TeamID)
continue;
if (Player->bDead)
continue;
if (Player->bHidden)
continue;
if (!Player->RootComponent)
continue;
if (Settings.Aim.nobot) {
if (Player->bEnsure)
continue;
}
if (Settings.Aim.knocked) {
if (Player->Health == 0.0f)
continue;
}
float dist = localPlayer->GetDistanceTo(Player) / 100.0f;    
if (dist > 300)//瞄准距离
continue;
if (Settings.Aim.vischeck) {
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,Player->GetBonePos("Head", {0, 0, 0}), false))//头
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,Player->GetBonePos("neck_01", {0, 0, 0}), false))//脖子
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,Player->GetBonePos("upperarm_r", {0, 0, 0}), false))//上面的肩膀右
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,Player->GetBonePos("upperarm_l", {0, 0, 0}), false))//上面的肩膀左
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,Player->GetBonePos("lowerarm_r", {0, 0, 0}), false))//上面的手臂右
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,Player->GetBonePos("lowerarm_l", {0, 0, 0}), false))//上面的手臂左
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,Player->GetBonePos("spine_03", {0, 0, 0}), false))//脊柱3
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,Player->GetBonePos("spine_02", {0, 0, 0}), false))//脊柱2
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,Player->GetBonePos("spine_01", {0, 0, 0}), false))//脊柱2
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,Player->GetBonePos("pelvis", {0, 0, 0}), false))//骨盆
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,Player->GetBonePos("thigh_l", {0, 0, 0}), false))//大腿左
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,Player->GetBonePos("thigh_r", {0, 0, 0}), false))//大腿右
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,Player->GetBonePos("calf_l", {0, 0, 0}), false))//小腿左
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager,Player->GetBonePos("calf_r", {0, 0, 0}), false))//小腿右
continue;
}

static bool 已选择 = false;
算法 = 0;
已选择 = false;
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager, Player->GetBonePos("Head", {0, 0, 0}),  false)) {//头
is头 = false;
}else{
is头 = true;
}
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager, Player->GetBonePos("pelvis", {0, 0, 0}),  false))
{//骨盆
is盆骨 = false;
}else{
is盆骨 = true;
}


if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager, Player->GetBonePos("neck_01", {0, 0, 0}),  false))
{//脖子
is脖子 = false;
}else{
is脖子 = true;
}


if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager, Player->GetBonePos("hand_l", {0, 0, 0}),  false))
{//左手
is左手 = false;
}else{
is左手 = true;
}


if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager, Player->GetBonePos("hand_r", {0, 0, 0}),  false))
{//右手
is右手 = false;
}else{
is右手 = true;
}

if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager, Player->GetBonePos("foot_l", {0, 0, 0}),  false))
{//左脚
is左脚 = false;
}else{
is左脚 = true;
}

if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager, Player->GetBonePos("foot_r", {0, 0, 0}),  false))
{//右脚
is右脚 = false;
}else{
is右脚 = true;
}

if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager, Player->GetBonePos("calf_l", {0, 0, 0}),  false))
{//左小腿
is左小腿 = false;
}else{
is左小腿 = true;
}

if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager, Player->GetBonePos("calf_r", {0, 0, 0}),  false))
{//右小腿
is右小腿 = false;
}else{
is右小腿 = true;
}

if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager, Player->GetBonePos("lowerarm_l", {0, 0, 0}),  false))
{//左小臂
is左小臂 = false;
}else{
is左小臂 = true;
}
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager, Player->GetBonePos("lowerarm_r", {0, 0, 0}),  false))
{//右小臂
is右小臂 = false;
}else{
is右小臂 = true;
}

if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager, Player->GetBonePos("thigh_l", {0, 0, 0}),  false))
{//左上臂
is左大腿 = false;
}else{
is左大腿 = true;
}
if(!localPlayerController->LineOfSightTo(localPlayerController->PlayerCameraManager, Player->GetBonePos("thigh_r", {0, 0, 0}),  false))
{//左上臂
is右大腿 = false;
}else{
is右大腿 = true;
}
if (!已选择)
if(is头) {
算法 = 1;
已选择 = true;
}else{
已选择 = false;
}
if (!已选择)
if(is盆骨)
{
算法 = 2;
已选择 = true;
}else{
已选择 = false;
}
if (!已选择)
if(is左小腿)
{
算法 = 3;
已选择 = true;
}else{
已选择 = false;
}
if (!已选择)
if(is右小腿)
{
算法 = 4;   
已选择 = true;
}else{
已选择 = false;
}
if (!已选择)
if(is左小臂)
{
算法 = 5;
已选择 = true;
}else{
已选择 = false;
}
if (!已选择)
if(is右小臂)
{
算法 = 6;
已选择 = true;
}else{
已选择 = false;
}
if (!已选择)
if(is左上臂)
{
算法 = 7;
已选择 = true;
}else{
已选择 = false;
}
if (!已选择)
if(is右上臂)
{
算法 = 8;
已选择 = true;
}else{
已选择 = false;
}
if (!已选择)
if(is左大腿)
{
算法 = 9;
已选择 = true;
}else{
已选择 = false;
}
if (!已选择)
if(is右大腿)
{
算法 = 10;
已选择 = true;
}else{//Config
已选择 = false;
}
if (!已选择)
if(is左脚)
{
算法 = 11;
已选择 = true;
}else{
已选择 = false;
}
if (!已选择)
if(is右脚)
{
算法 = 12;
已选择 = true;
}else{
已选择 = false;
}
auto Root = Player->GetBonePos("Root", {});
auto Head = Player->GetBonePos("Head", {});
FVector2D RootPosSC, HeadSc;
if (W2S(Root, &RootPosSC) && W2S(Head, &HeadSc))
{
float height = abs(HeadSc.Y - RootPosSC.Y);
float width = height * 0.65;//0.65
FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2),0};
if ((middlePoint.X >= 0 && middlePoint.X <= screenWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= screenHeight))
{
FVector2D v2Middle = FVector2D((float)(screenWidth / 2), (float)(screenHeight / 2));
FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);
if(isInsideFOV((int)middlePoint.X, (int)middlePoint.Y)) {
float dist = FVector2D::Distance(v2Middle, v2Loc);
if (dist < max) {
max = dist;
result = Player;
}}}}}}   
return result;
}






void (*orig_UpdateVolley)(USTExtraShootWeaponComponent *a1, FVector TargetLoc, FVector* start, FRotator* BulletRot, FVector* BulletDir);
void UpdateVolley(USTExtraShootWeaponComponent *a1, FVector TargetLoc, FVector* start, FRotator* BulletRot, FVector* BulletDir) {
    if (Settings.Aim.aim) {
        int hitRate = rand() % 100;
        if (hitRate <= hitRate) {
            ASTExtraPlayerCharacter* Target = Preferredhead();
            if (Target) {
                bool triggerOk = false;
                if (Settings.Aim.trigger == 0) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring;
                } else if (Settings.Aim.trigger == 1) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;
                }
                if (triggerOk) {
                    FVector targetAimPos;
                    if (Settings.Aim.location == 0) {
                        // 根据算法值选择目标骨骼
                        switch (算法) {
                            case 1:
                                targetAimPos = Target->GetBonePos("Head", {});
                                break;
                            case 2:
                                targetAimPos = Target->GetBonePos("pelvis", {});
                                break;
                            case 3:
                                targetAimPos = Target->GetBonePos("calf_l", {});
                                break;
                            case 4:
                                targetAimPos = Target->GetBonePos("calf_r", {});
                                break;
                            case 5:
                                targetAimPos = Target->GetBonePos("lowerarm_l", {});
                                break;
                            case 6:
                                targetAimPos = Target->GetBonePos("lowerarm_r", {});
                                break;
                            case 7:
                                targetAimPos = Target->GetBonePos("upperarm_l", {});
                                break;
                            case 8:
                                targetAimPos = Target->GetBonePos("upperarm_r", {});
                                break;
                            case 9:
                                targetAimPos = Target->GetBonePos("thigh_l", {});
                                break;
                            case 10:
                                targetAimPos = Target->GetBonePos("thigh_r", {});
                                break;
                            case 11:
                                targetAimPos = Target->GetBonePos("foot_l", {});
                                break;
                            case 12:
                                targetAimPos = Target->GetBonePos("foot_r", {});
                                break;
                            default:
                                targetAimPos = Target->GetBonePos("Head", {});
                                break;
                        }
                    } 

UShootWeaponEntity *ShootWeaponEntityComponent = a1->ShootWeaponEntityComponent;
                    if (ShootWeaponEntityComponent) {
                        float dist = g_LocalPlayer->GetDistanceTo(Target);
                        float timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;
                        FVector Velocity = Target->CurrentVehicle ? 
                            Target->CurrentVehicle->ReplicatedMovement.LinearVelocity : 
                            Target->GetVelocity();
                        targetAimPos += Velocity * timeToTravel;
                        FRotator sex = ToRotator(*start, targetAimPos);
                        BulletRot->Pitch = sex.Pitch;
                        BulletRot->Yaw = sex.Yaw;
                        // 计算从起始位置到目标瞄准位置的旋转角度
  
                    }
                }
            }
        }
    }
    // 如果没有满足自定义瞄准条件，则调用原始的 UpdateVolley 函数
    orig_UpdateVolley(a1, TargetLoc, start, BulletRot, BulletDir);
}



void* (*orig_PostRender)(UGameViewportClient* ViewportClient, UCanvas* Canvas);
void* new_PostRender(UGameViewportClient* ViewportClient, UCanvas* Canvas) {

// #include "Tools/过检测.h"

if (检测调试器()) {
exit(-1);
}
for (int i = 0; i < 10; i++) {
干扰变量[rand() % 100] = rand() % 1000;
}
if (真实验证) {
if (!辅助验证1 || 辅助验证2 != (随机种子 ^ 0x12345678)) {
exit(-1);
}
}
auto 校验逻辑1 = [](){ return 辅助验证1; };
auto 校验逻辑2 = [](){ return 辅助验证2 == (随机种子 ^ 0x12345678); };
if (真实验证 && (!校验逻辑1() || !校验逻辑2())) {
exit(-1);
}



	ASTExtraPlayerCharacter* localPlayer = 0;
	ASTExtraPlayerController* localPlayerController = 0;

	screenSizeX = ANativeWindow_getWidth(g_App->window);
	screenSizeY = ANativeWindow_getHeight(g_App->window);

    screenWidth = Canvas->SizeX;
	screenHeight = Canvas->SizeY;
	if (Canvas) {
	}



	if (Canvas) {
	
	
if (明日香美化) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x70, 1406387);//枪械C4E0EC6

          }

if (蓝木乃伊) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x70, 1406891);//枪械C4E0EC6
          }          

if (祖国人) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x70, 1406439);//枪械C4E0EC6

}

if (猴子) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x70, 1402627);//枪械C4E0EC6

          }

if (大丧尸) {

writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x70, 1407195);//枪械C4E0EC6

}


if (小丧尸) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x70, 1407196);//枪械C4E0EC6
}

if (黄金风衣) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x70, 1400779);//枪械C4E0EC6

}
if (神羽恋人) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x70, 1407276);//枪械C4E0EC6

}
if (烈焰古神) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x70, 1407277);//枪械C4E0EC6

}
if (果冻美化) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x188, 0);//枪械C4E0EC6

}

if (枫) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x70, 1406469);//枪械C4E0EC6

}

if (枫1) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x70, 1407259);//枪械C4E0EC6

}
if (枫2) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x70, 1406971);//枪械C4E0EC6
}

if (枫3) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x70, 1404330);//枪械C4E0EC6
}

if (头) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x118, 1502003389);//枪械C4E0EC6}
}
if (包) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x118, 1501003581);//枪械C4E0EC6
}
if (枪) {

writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x188, 0);//枪械C4E0EC6
}
if (小丑背包) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x188, 1501003051);//枪械C4E0EC6
}
if (法老背包) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x188, 1501003174);//枪械C4E0EC6
}
if (天使背包) {
    writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x188, 1501003081);//枪械C4E0EC6
}
if (血鸦圣装背包) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x188, 1501003220);//枪械C4E0EC6
}
if (封印幽冥M4) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x28F8)+0x9D0)+0x11C, 1101003195);//枪械
}
if (M4武魂宗师) {
    writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x28F8)+0x9D0)+0x11C, 1101004201);//枪械
}
if (M4小丑) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x28F8)+0x9D0)+0x11C, 1101004226);//枪械
}
if (冰霜M4) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x28F8)+0x9D0)+0x11C, 1101004046);//枪械

}
if (龙吟妹控) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x28F8)+0x9D0)+0x11C, 1103007028);//枪械
}
if (胖达头盔){
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x118, 1502003027);
}


if (隐藏头盔){
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x2C60)+0x388)+0x118, 0);//枪械C4E0EC6
}
 if (风鸣神戟) {
writedword(readValueL(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x440)+0x28F8)+0x9D0)+0x11C, 1105010019);

}	


	
		auto Actors = GetActors();
		UGameplayStatics* gGameplayStatics = (UGameplayStatics*)UGameplayStatics::StaticClass();
		auto GWorld = GetWorld();
		if (GWorld)
		{
			UNetDriver* NetDriver = GWorld->NetDriver;
			if (NetDriver)
			{
				UNetConnection* ServerConnection = NetDriver->ServerConnection;
				if (ServerConnection)
				{
					localPlayerController = (ASTExtraPlayerController*)ServerConnection->PlayerController;
				}
			}

			if (localPlayerController) {
				std::vector<ASTExtraPlayerCharacter*> PlayerCharacter;
				GetAllActors(PlayerCharacter);
				for (auto actor = PlayerCharacter.begin();
					actor != PlayerCharacter.end(); actor++) {
					auto Actor = *actor;
					if (Actor->PlayerKey == ((ASTExtraPlayerController*)localPlayerController)->PlayerKey) {
						localPlayer = Actor;
						break;
					}
				}				         							    				   			    				
			    if (localPlayer) {
				if (localPlayer->PartHitComponent) {
			    auto ConfigCollisionDistSqAngles = localPlayer->PartHitComponent->ConfigCollisionDistSqAngles;
				for (int j = 0; j < ConfigCollisionDistSqAngles.Num(); j++) {
				ConfigCollisionDistSqAngles[j].Angle = 180.0f;
				}
				localPlayer->PartHitComponent->ConfigCollisionDistSqAngles = ConfigCollisionDistSqAngles;
				}
				
                if (Settings.Aim.漏打自瞄){
                ASTExtraPlayerCharacter *Target = Preferredhead();
		        if (Target) {
			    bool triggerOk = false;
		   	    if (Settings.Aim.trigger == 0) {
				triggerOk = g_LocalPlayer->bIsWeaponFiring;
			    }
			    else if (Settings.Aim.trigger == 1) {
				triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;
			    }
			    if (triggerOk) {
			    FVector targetAimPos;
				if (Settings.Aim.location == 0) {
		           	    if(算法 == 1) {
                        targetAimPos = Target->GetBonePos("Head", {});
                        }else if(算法 == 2){
                        targetAimPos = Target->GetBonePos("pelvis", {});//锁骨
                        }else if(算法 == 3){
                        targetAimPos = Target->GetBonePos("calf_l", {});//左小腿
                        }else if(算法 == 4){
                        targetAimPos = Target->GetBonePos("calf_r", {});//右小腿
                        }else if(算法 == 5){
                        targetAimPos = Target->GetBonePos("lowerarm_l", {});//左小臂
                        }else if(算法 == 6){
                        targetAimPos = Target->GetBonePos("lowerarm_r", {});//右小臂
                        }else if(算法 == 7){
                        targetAimPos = Target->GetBonePos("upperarm_l", {});//左上臂
                        }else if(算法 == 8){
                        targetAimPos = Target->GetBonePos("upperarm_r", {});//右上臂
                        }else if(算法 == 9) {
                        targetAimPos = Target->GetBonePos("thigh_l", {});//左大腿
                        }else if(算法 == 10) {
                        targetAimPos = Target->GetBonePos("thigh_r", {});//右大腿
                        }else if(算法 == 11) {
                        targetAimPos = Target->GetBonePos("foot_l", {});//左脚
                        }else if(算法 == 12){
                        targetAimPos = Target->GetBonePos("foot_r", {});//右脚
					}
				}
            auto WeaponManagerComponent = g_LocalPlayer->WeaponManagerComponent;
            if (WeaponManagerComponent) {
                auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                if ((int)propSlot.GetValue() >= 1 && (int)propSlot.GetValue() <= 3) {
                    auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
                    if (CurrentWeaponReplicated) {
                        auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                        if (ShootWeaponComponent) {
                            UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
                            if (ShootWeaponEntityComponent) {
                                // 获取目标的当前速度
                                ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                                float dist = g_LocalPlayer->GetDistanceTo(Target);
                                float timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;

                                // 预测目标位置
                                if (CurrentVehicle) {
                                    FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;
                                    targetAimPos.X += LinearVelocity.X * timeToTravel;
                                    targetAimPos.Y += LinearVelocity.Y * timeToTravel;
                                    targetAimPos.Z += LinearVelocity.Z * timeToTravel;
                                } else {
                                    FVector Velocity = Target->GetVelocity();
                                    targetAimPos.X += Velocity.X * timeToTravel;
                                    targetAimPos.Y += Velocity.Y * timeToTravel;
                                    targetAimPos.Z += Velocity.Z * timeToTravel;
                                }

                                // 压枪算法
                                if (g_LocalPlayer->bIsWeaponFiring) {
                                    float dist = g_LocalPlayer->GetDistanceTo(Target) / 100.f;
                                    targetAimPos.Z -= dist * 1.0f; // 压枪
                                }
                                }
				}}}}}}}				
				
if (Settings.Aim.aim) {
    auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
    if (WeaponManagerComponent) {
        auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
        if ((int)propSlot.GetValue() >= 1 && (int)propSlot.GetValue() <= 3) {
            auto CurrentWeaponReplicated = (ASTExtraShootWeapon*)WeaponManagerComponent->CurrentWeaponReplicated;
            if (CurrentWeaponReplicated) {
                auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                if (ShootWeaponComponent) {
                    int UpdateVolley_idx = 157;
                    auto VTable = *(void***)(ShootWeaponComponent);
                    if (VTable) {
                        if (VTable[UpdateVolley_idx] != UpdateVolley) {
                            orig_UpdateVolley = decltype(orig_UpdateVolley)(VTable[UpdateVolley_idx]);
                            VTable[UpdateVolley_idx] = reinterpret_cast<void*>(&UpdateVolley);
                        }
                    }
                }
            }
        }
    }
}
                

                    static bool IsVisible;
					int totalEnemies = 0, totalBots = 0;
					std::vector<ASTExtraPlayerCharacter*> PlayerCharacter;
					GetAllActors(PlayerCharacter);
					for (auto actor = PlayerCharacter.begin(); actor != PlayerCharacter.end(); actor++)
					{
						auto Player = *actor;
						if (Player->PlayerKey == localPlayer->PlayerKey)
							continue;

						if (Player->TeamID == localPlayer->TeamID)
							continue;

						if (Player->bDead)
							continue;

						if (Player->bHidden)
							continue;

						if (!Player->RootComponent)
							continue;

						if (Settings.Character.nobot) {
							if (Player->bEnsure)
								continue;
						}

						if (Player->bEnsure)
							totalBots++;
						else totalEnemies++;

						FLinearColor pColor = 红色;
						FLinearColor bColor = 白色;
					    IsVisible = localPlayerController->LineOfSightTo(Player, { 0, 0, 0 }, true);
						float Distance = localPlayer->GetDistanceTo(Player) / 100.0f;

						int TeamID = Player->TeamID;
						bool bIsAI = Player->bEnsure;

						FVector pLocation = Player->K2_GetActorLocation();
						FVector sLocation = localPlayer->K2_GetActorLocation();

						FVector HeadPos = GetBoneLocation(Player, "Head");
						FVector2D HeadPosSC;
						FVector RootPos = GetBoneLocation(Player, "Root");
						FVector2D RootPosSC;
						FVector Root = GetBoneLocation(Player, "Root");
						FVector Spin = GetBoneLocation(Player, "pelvis");
						FVector Spin2 = GetBoneLocation(Player, "spine_03");
						FVector pelvis = GetBoneLocation(Player, "pelvis");
						FVector2D pelvisPoSC;
						FVector upper_r = GetBoneLocation(Player, "upperarm_r");
						FVector2D upper_rPoSC;
						FVector lowerarm_r = GetBoneLocation(Player, "lowerarm_r");
						FVector2D lowerarm_rPoSC;
						FVector lowerarm_l = GetBoneLocation(Player, "lowerarm_l");
						FVector2D lowerarm_lSC;
						FVector hand_r = GetBoneLocation(Player, "hand_r");
						FVector2D hand_rPoSC;
						FVector upper_l = GetBoneLocation(Player, "upperarm_l");
						FVector2D upper_lPoSC;
						FVector hand_l = GetBoneLocation(Player, "hand_l");
						FVector2D hand_lPoSC;
						FVector thigh_l = GetBoneLocation(Player, "thigh_l");
						FVector2D thigh_lPoSC;
						FVector calf_l = GetBoneLocation(Player, "calf_l");
						FVector2D calf_lPoSC;
						FVector foot_l = GetBoneLocation(Player, "foot_l");
						FVector2D foot_lPoSC;
						FVector thigh_r = GetBoneLocation(Player, "thigh_r");
						FVector2D thigh_rPoSC;
						FVector calf_r = GetBoneLocation(Player, "calf_r");
						FVector2D calf_rPoSC;
						FVector foot_r = GetBoneLocation(Player, "foot_r");
						FVector2D foot_rPoSC;
						FVector neck_01 = GetBoneLocation(Player, "neck_01");
						FVector2D neck_01PoSC;
						FVector spine_01 = GetBoneLocation(Player, "spine_01");
						FVector2D spine_01PoSC;
						FVector spine_02 = GetBoneLocation(Player, "spine_02");
						FVector2D spine_02PoSC;
						FVector spine_03 = GetBoneLocation(Player, "spine_03");
						FVector2D spine_03PoSC;
						

						if (Settings.Other.radar) {
						float Rotation = Player->K2_GetActorRotation().Yaw;
						float radar_x = Settings.Other.radarsize.X;
						float radar_y = Settings.Other.radarsize.Y;
						float radar_wh = screenHeight * 0.2461111111111 * 0.5; // 缩小到原来的一半
						float MapPosScreenX = (pLocation.X - sLocation.X) / 200 + radar_x + radar_wh / 2;
						float MapPosScreenY = (pLocation.Y - sLocation.Y) / 200 + radar_y + radar_wh / 2;
						float MapDis = sqrt(pow(radar_x + radar_wh / 2 - MapPosScreenX, 2) + pow(radar_y + radar_wh / 2 - MapPosScreenY, 2));
						if (MapDis < radar_wh / 2)
						{
						DrawRadarGrid(Canvas, radar_x, radar_y, radar_wh, 白色, 1.0f);
						float playerYaw = localPlayerController->K2_GetActorRotation().Yaw;
						float yawInRadians = (playerYaw) * (M_PI / 180.0f);

						float lineEndX = radar_x + radar_wh / 2 + 45 * std::cos(yawInRadians); // 90 缩小到 45
						float lineEndY = radar_y + radar_wh / 2 + 45 * std::sin(yawInRadians); // 90 缩小到 45

						DrawLine(Canvas, FVector2D(radar_x + radar_wh / 2, radar_y + radar_wh / 2), FVector2D(lineEndX, lineEndY), 1.0f, 红色);
						DrawFilledCircle(Canvas, { MapPosScreenX + 5, MapPosScreenY + 6.5 }, 3.75, bIsAI ? bColor : arr[TeamID % length]); // 半径 7.5 缩小到 3.75
						    }
						}

                       
						if (gGameplayStatics->ProjectWorldToScreen(g_PlayerController, HeadPos, false, &HeadPosSC) &&												
							gGameplayStatics->ProjectWorldToScreen(g_PlayerController, RootPos, false, &RootPosSC)) {
							Rect box;
							box.x = HeadPosSC.X - (RootPosSC.Y - HeadPosSC.Y) / 4;
							box.y = HeadPosSC.Y - 20;
							box.width = (RootPosSC.Y - HeadPosSC.Y) / 2;
							box.height = RootPosSC.Y - box.y;

if (Settings.Character.skeleton) {
    static std::vector<std::string> right_arm{"neck_01", "clavicle_r", "upperarm_r", "lowerarm_r", "hand_r", "item_r"};
    static std::vector<std::string> left_arm{"neck_01", "clavicle_l", "upperarm_l", "lowerarm_l", "hand_l", "item_l"};
    static std::vector<std::string> spine{"Head", "neck_01", "spine_03", "spine_02", "spine_01", "pelvis"};
    static std::vector<std::string> lower_right{"pelvis", "thigh_r", "calf_r", "foot_r"};
    static std::vector<std::string> lower_left{"pelvis", "thigh_l", "calf_l", "foot_l"};
    static std::vector<std::vector<std::string>> skeleton{right_arm, left_arm, spine, lower_right, lower_left};

    // 定义彩虹颜色数组（深色和浅色）
    FLinearColor DeepRainbowColors[7] = {
        {1.0f, 0.0f, 0.0f, 1.0f},    // 红
        {1.0f, 0.65f, 0.0f, 1.0f},  // 橙
        {1.0f, 1.0f, 0.0f, 1.0f},   // 黄
        {0.0f, 0.5f, 0.0f, 1.0f},   // 绿
        {0.0f, 0.0f, 1.0f, 1.0f},   // 蓝
        {0.29f, 0.0f, 0.51f, 1.0f}, // 靛
        {0.55f, 0.17f, 0.89f, 1.0f} // 紫
    };

    FLinearColor LightRainbowColors[7] = {
        {1.0f, 0.7f, 0.7f, 1.0f},    // 浅红
        {1.0f, 0.85f, 0.7f, 1.0f},   // 浅橙
        {1.0f, 1.0f, 0.7f, 1.0f},    // 浅黄
        {0.7f, 1.0f, 0.7f, 1.0f},    // 浅绿
        {0.7f, 0.7f, 1.0f, 1.0f},    // 浅蓝
        {0.85f, 0.7f, 1.0f, 1.0f},   // 浅靛
        {1.0f, 0.8f, 1.0f, 1.0f}     // 浅紫
    };

    // 动态选择颜色（可以根据时间或其他条件选择颜色）
    static float TimeAccumulator = 0.0f;
    TimeAccumulator += 0.033f; // 假设每帧时间增量为 0.033 秒
    int ColorIndex = static_cast<int>(fmod(TimeAccumulator, 7.0f)); // 0 到 6 之间循环

    // 根据目标是否可见选择颜色组
    FLinearColor* SelectedColors = IsVisible ? DeepRainbowColors : LightRainbowColors;

    for (auto &boneStructure : skeleton) {
        std::string lastBone;

        for (std::string &currentBone : boneStructure) {
            if (!lastBone.empty()) {
                FVector2D boneFrom, boneTo;

                if (W2S(Player->GetBonePos(lastBone.c_str(), {}), (FVector2D *)&boneFrom) && 
                    W2S(Player->GetBonePos(currentBone.c_str(), {}), (FVector2D *)&boneTo)) {

                    // 使用彩虹渐变颜色
                    FLinearColor BoneColor = SelectedColors[ColorIndex];

                    // 使用 DrawLine 函数绘制骨骼
                    DrawLine(Canvas, boneFrom, boneTo, 1.0f, BoneColor);
                }
            }

            lastBone = currentBone;
        }
    }
}


// 定义彩虹颜色数组（深色和浅色）
FLinearColor DeepRainbowColors[7] = {
    {1.0f, 0.0f, 0.0f, 1.0f},    // 红
    {1.0f, 0.65f, 0.0f, 1.0f},  // 橙
    {1.0f, 1.0f, 0.0f, 1.0f},   // 黄
    {0.0f, 0.5f, 0.0f, 1.0f},   // 绿
    {0.0f, 0.0f, 1.0f, 1.0f},   // 蓝
    {0.29f, 0.0f, 0.51f, 1.0f}, // 靛
    {0.55f, 0.17f, 0.89f, 1.0f} // 紫
};

FLinearColor LightRainbowColors[7] = {
    {1.0f, 0.7f, 0.7f, 1.0f},    // 浅红
    {1.0f, 0.85f, 0.7f, 1.0f},   // 浅橙
    {1.0f, 1.0f, 0.7f, 1.0f},    // 浅黄
    {0.7f, 1.0f, 0.7f, 1.0f},    // 浅绿
    {0.7f, 0.7f, 1.0f, 1.0f},    // 浅蓝
    {0.85f, 0.7f, 1.0f, 1.0f},   // 浅靛
    {1.0f, 0.8f, 1.0f, 1.0f}     // 浅紫
};

// 动态选择颜色（可以根据时间或其他条件选择颜色）
static float TimeAccumulator = 0.0f;
TimeAccumulator += 0.033f; // 假设每帧时间增量为 0.033 秒
int ColorIndex = static_cast<int>(fmod(TimeAccumulator, 7.0f)); // 0 到 6 之间循环

// 根据目标是否可见选择颜色组
FLinearColor* SelectedColors = IsVisible ? DeepRainbowColors : LightRainbowColors;
FLinearColor LineColor = SelectedColors[ColorIndex];

// 绘制骨骼射线
if (Settings.Character.line) {
    DrawLine(Canvas, { static_cast<float>(screenWidth / 2), 97 }, FVector2D(HeadPosSC.X, HeadPosSC.Y - 98), 1.0f, LineColor);
}

		if (Settings.Character.info) {
    // 血量计算（增加安全校验）
    float CurHP = std::max(0.f, std::min(Player->Health, Player->HealthMax));
    float MaxHP = Player->HealthMax ? Player->HealthMax : 1.0f; // 防除零崩溃
    float PercentHP = CurHP / MaxHP;

    // 生成百分比文本（符合网页2的文本处理规范）
    char hpStr[16];
    snprintf(hpStr, sizeof(hpStr), "%.0f%%", PercentHP * 100); // 自动四舍五入

    // 圆心坐标计算（网页1的UI定位方法）
    FVector2D CircleCenter(HeadPosSC.X, HeadPosSC.Y - 45);
    
    // 绘制彩虹血环（保持原有参数）
    圆形血量(Canvas, CircleCenter.X, CircleCenter.Y, 18, 100, 0, 2*PI*PercentHP, arr[TeamID%length]);

    // 文本居中显示（基于网页2的坐标修正）
    const float TextWidth = strlen(hpStr)*10; // 经验值：10px/字符
    const float TextHeight = 20; // 字号高度
    FVector2D TextPos(
        CircleCenter.X - TextWidth/20, // 水平居中
        CircleCenter.Y - TextHeight/2 // 垂直居中
    );
    
    // 调用原始DrawText函数（兼容性处理）
    DrawText(Canvas, 
        hpStr, 
        TextPos,
        FLinearColor(1.0f,1.0f,1.0f,1.0f), // 白色高亮
        黑色, // 描边颜色
        14, // 字号
        true // 启用抗锯齿
    );
}



if (Settings.Character.info) {
    // 确保 HeadPosSC 和 RootPosSC 是有效的
    if (!isnan(HeadPosSC.X) && !isnan(HeadPosSC.Y) && !isnan(RootPosSC.Y)) {
        // 计算矩形框的尺寸
        float boxHeight = abs(HeadPosSC.Y - RootPosSC.Y);
        float boxWidth = boxHeight * 0.65f;

        // 定义彩虹颜色数组（深色和浅色）
        FLinearColor DeepRainbowColors[7] = {
            {1.0f, 0.0f, 0.0f, 1.0f},    // 红
            {1.0f, 0.65f, 0.0f, 1.0f},  // 橙
            {1.0f, 1.0f, 0.0f, 1.0f},   // 黄
            {0.0f, 0.5f, 0.0f, 1.0f},   // 绿
            {0.0f, 0.0f, 1.0f, 1.0f},   // 蓝
            {0.29f, 0.0f, 0.51f, 1.0f}, // 靛
            {0.55f, 0.17f, 0.89f, 1.0f} // 紫
        };

        FLinearColor LightRainbowColors[7] = {
            {1.0f, 0.7f, 0.7f, 1.0f},    // 浅红
            {1.0f, 0.85f, 0.7f, 1.0f},   // 浅橙
            {1.0f, 1.0f, 0.7f, 1.0f},    // 浅黄
            {0.7f, 1.0f, 0.7f, 1.0f},    // 浅绿
            {0.7f, 0.7f, 1.0f, 1.0f},    // 浅蓝
            {0.85f, 0.7f, 1.0f, 1.0f},   // 浅靛
            {1.0f, 0.8f, 1.0f, 1.0f}     // 浅紫
        };

        // 根据目标是否可见选择颜色组
        FLinearColor* SelectedColors = IsVisible ? DeepRainbowColors : LightRainbowColors;

        // 动态选择颜色（可以根据时间或其他条件选择颜色）
        static float TimeAccumulator = 0.0f;
        TimeAccumulator += 0.033f; // 假设每帧时间增量为 0.033 秒
        int ColorIndex = static_cast<int>(fmod(TimeAccumulator, 7.0f)); // 0 到 6 之间循环

        // 选择对应的颜色
        FLinearColor BoxColor = SelectedColors[ColorIndex];

        // 绘制矩形框
        Box4Line(Canvas, 1.5f, HeadPosSC.X - (boxWidth / 2), HeadPosSC.Y, boxWidth, boxHeight, BoxColor);
    }
}


							if (Settings.Character.alert) {
							
								FVector2D screen(screenWidth, screenHeight);
								FVector2D location(RootPosSC.X, HeadPosSC.Y);
								int borders = isOutsideSafezone(location, screen);
								float mScale = screenHeight / (float)screenWidth;
								if (Settings.Character.alert && borders != 0)
								{									
								    std::wstring s = std::to_wstring((int)Distance) + L" M";
								    
									auto hintTextRenderPos = pushToScreenBorder(location, screen, borders, -(int)((mScale * 50)));								    
									DrawBox(Canvas, { (hintTextRenderPos.X) - 55, (hintTextRenderPos.Y) - 40 }, { 75,40 }, bIsAI ? 白色 : arr[TeamID % length]);
									DrawRectangle(Canvas, { (hintTextRenderPos.X) - 55, (hintTextRenderPos.Y) - 40 }, 76, 41, 2.0f, 白色);
									DrawText(Canvas,  FString(s), { hintTextRenderPos.X - 38, hintTextRenderPos.Y - 31 }, 黑色, 白色, 20, false);
								}
							}
						
				
					if (Settings.Other.vehicle) {
						std::vector<ASTExtraVehicleBase*> VehicleBase;
						GetAllActors(VehicleBase);
						for (auto actor = VehicleBase.begin(); actor != VehicleBase.end(); actor++) {
							auto Vehicle = *actor;
							if (!Vehicle->Mesh)
								continue;

							FVector2D vehiclePos;
							auto vehicleicon = Vehicle->VehicleIcon;
							if (W2S(Vehicle->K2_GetActorLocation(), &vehiclePos))
							{
								Canvas->K2_DrawTexture(vehicleicon, FVector2D(vehiclePos.X - 45, vehiclePos.Y - 70), FVector2D(64, 64), FVector2D{ 0,0 }, FVector2D{ 1,1 }, FLinearColor{ 0, 1, 1, 1.0f }, EBlendMode::BLEND_Translucent, 0, {});
							}
						}
					}
					if (Settings.Character.casket) {
					std::vector<APickUpListWrapperActor*> LootboxBase;
					GetAllActors(LootboxBase);
					for (auto actor = LootboxBase.begin(); actor != LootboxBase.end(); actor++) {
					auto Pick = *actor;                                        
					if (!Pick->RootComponent)
					continue;       
					float Distance = Pick->GetDistanceTo(localPlayer) / 100.0f;
					if (Distance > 150.0) // 骨灰盒显示最大距离
					continue;        
					FVector2D PickUpListsPos;
					if (W2S(Pick->K2_GetActorLocation(), &PickUpListsPos)) {
					std::string s = "盒子";
					s += "[";
					s += std::to_string((int)Distance);
					s += "米]";          
					DrawText(Canvas,FString(s),PickUpListsPos,红色,黑色,12,true);
					}
					}
					}
					if (Settings.Character.casket) {
					std::vector<ASTExtraSimpleCharacter*> 箱子列表;
					GetAllActors(箱子列表);
					for (auto actor = 箱子列表.begin(); actor != 箱子列表.end(); actor++) {
					auto 当前箱子 = *actor;
					APickUpListWrapperActor* Pick = (APickUpListWrapperActor*)当前箱子;
					if (!Pick->RootComponent)
					continue;
					float Distance = Pick->GetDistanceTo(localPlayer) / 50.f;
					FVector2D 箱子坐标;        
					if (W2S(Pick->K2_GetActorLocation(), &箱子坐标)) {
					std::string classname = 当前箱子->GetName();
					if (classname.find("ItemBox_Lua_Lv") != std::string::npos) {
					std::string level = classname.substr(11, 1);
					std::string s = "物资箱(" + level + "级)";
					s += "[";
					s += std::to_string((int)Distance);
					s += "m]";
					DrawText(Canvas, FString(s), 箱子坐标, 白色, 黑色, 12, true);
					}           
					if (classname.find("WeaponBox_Lua_Lv") != std::string::npos) {
					std::string level = classname.substr(13, 1);
					std::string s = "武器箱(" + level + "级)";
					s += "[";
					s += std::to_string((int)Distance);
					s += "m]";
					DrawText(Canvas, FString(s), 箱子坐标, 白色, 黑色, 12, true);
					}          
					if (classname.find("FileBox_Lua_Lv") != std::string::npos) {
					std::string level = classname.substr(10, 1);
					std::string s = "信函箱(" + level + "级)";
					s += "[";
					s += std::to_string((int)Distance);
					s += "m]";
					DrawText(Canvas, FString(s), 箱子坐标, 白色, 黑色, 12, true);
					}           
					if (classname.find("FileBag_Lua_Lv") != std::string::npos) {
					std::string level = classname.substr(10, 1);
					std::string s = "手提包(" + level + "级)";
					s += "[";
					s += std::to_string((int)Distance);
					s += "m]";
					DrawText(Canvas, FString(s), 箱子坐标, 白色, 黑色, 12, true);
					}            
					if (classname.find("EggBox_Lua_Lv1_C") != std::string::npos) {
					std::string s = "隐秘点";
					s += "[";
					s += std::to_string((int)Distance);
					s += "m]";
					DrawText(Canvas, FString(s), 箱子坐标, 白色, 黑色, 12, true);
					}           
					else if (classname.find("PlayerDeadInventoryBox") != std::string::npos) {
					std::string s = "\n箱子状态:已开启";
					s += "[";
					s += std::to_string((int)Distance);
					s += "m]";
					DrawText(Canvas, FString(s), 箱子坐标, 红色, 黑色, 12, true);
					}
					}
					}
					}
			            if (Settings.Other.grenade) {
						std::vector<ASTExtraGrenadeBase*>Grenade;
						GetAllActors(Grenade);
						for (auto actor = Grenade.begin(); actor != Grenade.end(); actor++) {
							auto Grenade = *actor;

							if (!Grenade->RootComponent)
								continue;

							float Distance = Grenade->GetDistanceTo(localPlayer) / 100.0f;
							
							if (Distance > 100.0)
								continue;
								
							FVector2D GrenadePos;
							if (W2S(Grenade->K2_GetActorLocation(), &GrenadePos)) {
								std::string classname = Grenade->GetName();
								if (classname.find("BP_Grenade_Shoulei_C") != std::string::npos) {
									std::string s = "==!!碎片手雷!!==";
									s += "[";
									s += std::to_string((int)Distance);
									s += "米]";
									DrawText(Canvas, FString(s), GrenadePos, 青绿, 黑色, 12, true);
								}
								if (classname.find("BP_Grenade_Burn_C") != std::string::npos) {

									std::string s = OBFUSCATE("==!!碎燃烧弹!!==");
									s += "[";
									s += std::to_string((int)Distance);
									s += "米]";
									DrawText(Canvas, FString(s), GrenadePos, 青绿, 黑色, 12, true);
								}
								if (classname.find("BP_Grenade_Stun_C") != std::string::npos) {

									std::string s = OBFUSCATE("==!!闪光弹!!==");
									s += "[";
									s += std::to_string((int)Distance);
									s += "米]";
									DrawText(Canvas, FString(s), GrenadePos, 青绿, 黑色, 12, true);
								}
								if (classname.find("BP_Grenade_Smoke_C") != std::string::npos) {

									std::string s = OBFUSCATE("==!!烟雾弹!!==");
									s += "[";
									s += std::to_string((int)Distance);
									s += "米]";
									DrawText(Canvas, FString(s), GrenadePos, 青绿, 黑色, 12, true);
								}
							}
						}
					}
				}
			}		
                    g_LocalPlayer = localPlayer;
                    g_PlayerController = localPlayerController;
                    std::wstring Bot;
					std::wstring Player; 
                    Bot += std::to_wstring(totalBots);
					Player += std::to_wstring(totalEnemies);                                                                   
					DrawFilledRect(Canvas, { (float)screenWidth / 2 - 40, 85 }, 80, 40, IsVisible ? FLinearColor(1, 1, 0, 0.2f) : FLinearColor(0, 1, 0, 0.2f));
					DrawLine(Canvas, { screenWidth / 2 - 40, 85 }, FVector2D(screenWidth / 2 + 40, 85 ), 1.0f, 红色);
					DrawLine(Canvas, { screenWidth / 2 - 40, 125 }, FVector2D(screenWidth / 2 + 40, 125 ), 1.0f, 绿色);
					DrawText(Canvas, FString(Player ), { (float)(float)screenWidth / 2, 90 }, FLinearColor(1, 0, 0, 1.0f), 白色, 20, true);
					if (totalBots >0 ) {
					DrawText(Canvas, FString(Bot ), { (float)(float)screenWidth / 2, 55 }, FLinearColor(0, 1, 0, 1.0f), 白色, 20, true);
					}					
										    
					if (Settings.Aim.aim||Settings.Aim.漏打自瞄) {
                    DrawRainbowCircle(Canvas, screenWidth/2, screenHeight/2, Settings.Aim.fovsize, 100, 1.5f);
                                                              
					}
					
if (Settings.Aim.漏打自瞄) {
    ASTExtraPlayerCharacter *Target = Preferredhead();
    if (Target) {
        bool triggerOk = false;


            triggerOk = g_LocalPlayer->bIsGunADS; // 只要瞄准就触发


        if (triggerOk) {
            static constexpr const char* BONE_NAMES[] = {
                nullptr,
                "Head", "neck_01", "clavicle_r", "upperarm_r", "lowerarm_r", "hand_r", 
                "item_r", "clavicle_l", "upperarm_l", "lowerarm_l", "hand_l", "item_l",
                "spine_03", "spine_02", "spine_01", "pelvis","thigh_r", "calf_r", "foot_r",
                "thigh_l", "calf_l", "foot_l"
            };

            FVector 锁定位置{};
            if (算法 >= 1 && 算法 <= 22) {
                锁定位置 = Target->GetBonePos(BONE_NAMES[算法], {});
            }

            // 将锁定位置投影到屏幕
            FVector2D HeadPosSC;
            if (gGameplayStatics->ProjectWorldToScreen(g_PlayerController, 锁定位置, false, &HeadPosSC)) {
                // 旋转角度（随着时间累积）
                static float AccumulatedTime = 0.0f;
                AccumulatedTime += 0.0334f; // 保持60FPS的动画速度
                float Rotation = AccumulatedTime;

                // 彩色圆形的绘制逻辑
                const float FullCircle = 2.0f * PI;
                const float Step = FullCircle / 7; // 7段渐变

                // 保持原始7色配置
                FLinearColor RainbowColors[7] = {
                    {1.0f, 0.0f, 0.0f, 1.0f},    // 红
                    {1.0f, 0.65f, 0.0f, 1.0f},  // 橙
                    {1.0f, 1.0f, 0.0f, 1.0f},   // 黄
                    {0.0f, 0.5f, 0.0f, 1.0f},   // 绿
                    {0.0f, 0.0f, 1.0f, 1.0f},   // 蓝
                    {0.29f, 0.0f, 0.51f, 1.0f}, // 靛
                    {0.55f, 0.17f, 0.89f, 1.0f} // 紫
                };

                // 颜色偏移计算（保持原始1.5倍速）
                float colorOffset = fmod(Rotation * 2.4f, 7.0f);

                for (int i = 0; i < 7; ++i) {
                    const float angle = i * Step + Rotation; // 加上旋转角度

                    // 颜色位置计算
                    float colorPos = (angle / FullCircle) * 7.0f + colorOffset;
                    colorPos = fmod(colorPos, 7.0f);

                    // 颜色插值
                    int idx1 = static_cast<int>(colorPos);
                    int idx2 = (idx1 + 1) % 7;
                    float blend = colorPos - idx1;

                    FLinearColor color;
                    color.R = RainbowColors[idx1].R * (1 - blend) + RainbowColors[idx2].R * blend;
                    color.G = RainbowColors[idx1].G * (1 - blend) + RainbowColors[idx2].G * blend;
                    color.B = RainbowColors[idx1].B * (1 - blend) + RainbowColors[idx2].B * blend;
                    color.A = 1.0f;

                    // 坐标计算
                    FVector2D start(15 * cos(angle) + HeadPosSC.X, 15 * sin(angle) + HeadPosSC.Y);
                    FVector2D end(15 * cos(angle + Step) + HeadPosSC.X, 15 * sin(angle + Step) + HeadPosSC.Y);

                    // 绘制彩色线条
                    Canvas->K2_DrawLine(start, end, 3.0f, color);
                }

                // 十字线的绘制逻辑，加入旋转
                float CrosshairRotation = Rotation; // 使用相同的旋转角度
                const float CrosshairLength = 10.0f; // 十字线长度
                const float CrosshairThickness = 3.0f; // 十字线粗细

                // 绘制十字线的上下部分
                FVector2D crosshairTop = HeadPosSC;
                FVector2D crosshairBottom = HeadPosSC;
                FVector2D crosshairLeft = HeadPosSC;
                FVector2D crosshairRight = HeadPosSC;

                crosshairTop.X += cos(CrosshairRotation) * CrosshairLength;
                crosshairTop.Y += sin(CrosshairRotation) * CrosshairLength;
                crosshairBottom.X -= cos(CrosshairRotation) * CrosshairLength;
                crosshairBottom.Y -= sin(CrosshairRotation) * CrosshairLength;
                crosshairLeft.X += sin(CrosshairRotation) * CrosshairLength;
                crosshairLeft.Y -= cos(CrosshairRotation) * CrosshairLength;
                crosshairRight.X -= sin(CrosshairRotation) * CrosshairLength;
                crosshairRight.Y += cos(CrosshairRotation) * CrosshairLength;

                Canvas->K2_DrawLine(crosshairTop, crosshairBottom, CrosshairThickness, FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
                Canvas->K2_DrawLine(crosshairLeft, crosshairRight, CrosshairThickness, FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
            }
        }
    }
}



if (防封) {
PATCH_LIB("libanogs.so", "0x1DDE64", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x2A3FE4", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x3601C4", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x3D1190", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x49D8D0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0x4D88F4", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x13B478","00 00 80 D2 CO 03 5F D6");
PATCH_LIB("libanogs.so","0x13C1A0","00 00 80 D2 CO 03 5F D6");
PATCH_LIB("libanogs.so","0x15A028","00 00 80 D2 CO 03 5F D6");
PATCH_LIB("libanogs.so","0x15B550","00 00 80 D2 CO 03 5F D6");
PATCH_LIB("libanogs.so","0x1633B0","00 00 80 D2 CO 03 5F D6");
}
					
// if (Settings.Aim.aim||Settings.Aim.漏打自瞄) {
// float Distance = localPlayer->GetDistanceTo(Preferredhead) / 100.0f;
// std::string 玩家名字 = Preferredhead->PlayerName.ToString();
// std::string xsnb;
// xsnb += "警告已漏：";
// xsnb += 玩家名字;
// xsnb += "【";
// xsnb += std::to_string((int)Distance);
// xsnb += "M】";
// DrawOutlinedText(Canvas, xsnb.c_str(), {(float)屏幕宽 / 2 - 430, 215}, 浅粉, 黑色, true);
// }
                
							
					
				}						
			}
        }
    


    
    bool 隐藏 = true;
float sy = 0.0f;
float sx = 0.0f;
bool 控件;
static bool 开关;
char info[50];
sprintf(info, OBFUSCATE("MOUSE直装 PUBGM-3.7\nTelegram -@MOUSE_MAD"));
DrawText(Canvas, FString(info), { (float)screenWidth / 8,  screenHeight - (float)screenWidth / 12 }, 白色, 黑色, 18, true);
ZeroGUI::SetupCanvas(Canvas, tslFont);
static FVector2D WindowPos = { 300,300 };
static float TempValue = 0;
static char windowTitleBuffer[64] = {0};
//static float 计时 = 100.0f;

/*if (开关 == true) {
计时 -= 20.0f;
if (计时 < 0)//如果到达此数值则固定
{
开关 = false;
计时 = 100.0f;//固定定义值
}
}

	   if (隐藏) {
ZeroGUI::SetupCanvas(Canvas, tslFont);
//ZeroGUI::NewFrame(screenSizeX, screenSizeY);
	    static FVector2D WindowPos = {300,300};
        static bool IsOpen = false;
        static bool 音量隐藏 = true;
        static float TempValue = 0;
        //	static int tab = 0;
        
        static float 屏宽 = 595.0f;
        static float 屏高 = 420.0f;
        static float 最小屏宽 = 350.0f;
        static float 最小屏高 = 25.0f;

if (IsOpen) {
sy += 15.5f;//调节开启的速度
sx += 15.5f;
if (sy > 屏高)//如果到达此数值则固定
{
sy = 屏高;//固定定义值
}
if (sx > 屏宽)//如果到达此数值则固定
{
sx = 屏宽;//固定定义值
}
if (sy == 屏高 && sx == 屏宽)//如果到达此数值则固定
{
控件 = true;
}
}else{
控件 = false; 
sy -= 16.5f;//调节开启的速度
sx -= 16.5f;
if (sy < 最小屏高)//如果到达此数值则固定
{
sy = 最小屏高;//固定定义值
}
if (sx < 最小屏宽)//如果到达此数值则固定
{
sx = 最小屏宽;//固定定义值
}
}

static float 计时 = 100.0f;

if (开关 == true) {
计时 -= 20.0f;
if (计时 < 0)//如果到达此数值则固定
{
开关 = false;
计时 = 100.0f;//固定定义值
}
}

       for (int i = 0; i < IM_ARRAYSIZE(ZeroGUI::KeysDown); i++) {
    if (ZeroGUI::IsKeyDown(i)) {
    if (i % 2 != 0) {
    音量隐藏 = false;
    }else {       
    音量隐藏 = true;
           }
        }
    }*/           
  /*  static float 屏宽 = 595.0f;
        static float 屏高 = 420.0f;
        static float 最小屏宽 = 350.0f;
        static float 最小屏高 = 25.0f;
if (IsOpen)
    {
        sy += 15.5f;
        sx += 15.5f;
        if (sy > 420.0f) sy = 420.0f;
        if (sx > 595.0f) sx = 595.0f;
 控件 = true;
    }
    else
    {
        控件 = false;
        sy -= 16.5f;
        sx -= 16.5f;
        if (sy < 25.0f) sy = 25.0f;
        if (sx < 350.0f) sx = 350.0f;
    }
*/
strncpy(windowTitleBuffer, 真实验证 ? "MOUSE直装 - 已登录" : "请登录！", sizeof(windowTitleBuffer)-1);
robotoFont->LegacyFontSize = 17;
//if (音量隐藏) {
if (ZeroGUI::Window(windowTitleBuffer, &WindowPos, { 595.0f, 420.0f }, IsOpen, TempValue)) {
if (!真实验证) {
static std::string err;
if (ZeroGUI::Button("粘贴", FVector2D({120, 50}))) {auto key = getClipboardText();strncpy(s, key.c_str(), sizeof s);}
if (ZeroGUI::Button("登陆", FVector2D({120, 50}))) { 登录(s);};  
if (ZeroGUI::Button("解绑", FVector2D({120, 50}))) { Unbind(s);}       
if (错误提示 && 提示 && strlen(提示) > 0) {
    ZeroGUI::Text("          错误: %s", 提示);
}

}else{
static int tab = 1;
if (ZeroGUI::ButtonTab("玩家绘制", FVector2D{ 120, 40 }, tab == 1)) tab = 1;

if (ZeroGUI::ButtonTab("子弹追踪", FVector2D{ 120, 40 }, tab == 2)) tab = 2;

if (ZeroGUI::ButtonTab("漏打自瞄", FVector2D{ 120, 40 }, tab == 3)) tab = 3;

if (ZeroGUI::ButtonTab("功能页面", FVector2D{ 120, 40 }, tab == 4)) tab = 4;    

if (ZeroGUI::ButtonTab("美化页面", FVector2D{ 120, 40 }, tab == 5)) tab = 5;

ZeroGUI::NextColumn(150.0f);
switch (tab) {
case 1://公告
ZeroGUI::Checkbox("射线", &Settings.Character.line);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("骨骼", &Settings.Character.skeleton);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("雷达", &Settings.Other.radar);

ZeroGUI::Checkbox("信息", &Settings.Character.info);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("手雷", &Settings.Other.grenade);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("载具", &Settings.Other.vehicle);

ZeroGUI::Checkbox("预警", &Settings.Character.alert);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("盒子", &Settings.Character.casket);       
ZeroGUI::SameLine();
ZeroGUI::Checkbox("忽机", &Settings.Character.nobot);       

ZeroGUI::SliderFloat(OBFUSCATE("雷达X轴"), &Settings.Other.radarsize.X, 0, screenWidth, "%.1f");
ZeroGUI::SliderFloat(OBFUSCATE("雷达Y轴"), &Settings.Other.radarsize.Y, 0, screenHeight, "%.1f");
if (ZeroGUI::Button(OBFUSCATE("保存配置"), FVector2D{ 110,40 })) {
	写入调试数据();
}
ZeroGUI::SameLine();
if (ZeroGUI::Button(OBFUSCATE("读取配置"), FVector2D{ 110,40 })) {
	加载调试数据();	
}


// if (ZeroGUI::Button(OBFUSCATE("解锁120帧数"), FVector2D(95, 30))) {
// auto objs = UObject::GetGlobalObjects();
        // for (int i = 0; i < objs.Num(); i++) {
            // auto Object = objs.GetByIndex(i);
         // if (isObjectInvalid(Object))
             // continue;
             
// if (Object->IsA(USTExtraGameInstance::StaticClass())) {
// auto playerChar = (USTExtraGameInstance *) Object;      
// playerChar->UserDetailSetting.PUBGDeviceFPSDef = 120.0f;   
// playerChar->UserDetailSetting.PUBGDeviceFPSLow = 120.0f;
// playerChar->UserDetailSetting.PUBGDeviceFPSMid = 120.0f;
// playerChar->UserDetailSetting.PUBGDeviceFPSHigh = 120.0f;
// playerChar->UserDetailSetting.PUBGDeviceFPSHDR = 120.0f;
// playerChar->UserDetailSetting.PUBGDeviceFPSUltralHigh = 120.0f;
// }
// }
// }
// ZeroGUI::SameLine();
// if (ZeroGUI::Button(OBFUSCATE("无限游客"), FVector2D(95, 30))) {
// system("chmod 777 /data/data/com.tencent.ig/files/image/无限游客.sh"); // 设置权限
// system("sh /data/data/com.tencent.ig/files/image/无限游客.sh"); // 尝试执行
// }
break;
case 2://绘制
ZeroGUI::滑动开关("弹道追踪(危险)", &Settings.Aim.aim);
ZeroGUI::SliderFloat(OBFUSCATE("追踪概率"), &概率触发, 0, 100, "%.1f");
ZeroGUI::SliderFloat(OBFUSCATE("圈圈大小"), &Settings.Aim.fovsize, 0, 650.0, "%.1f");
ZeroGUI::Combobox(OBFUSCATE("锁定方式"), FVector2D{ 390,45 }, &Settings.Aim.location, "漏打智能优先锁定胸部", "漏打智能优先锁定头部", NULL);
ZeroGUI::Combobox(OBFUSCATE("触发方式"), FVector2D{ 390,45 }, &Settings.Aim.trigger, "开火", "同时", NULL);   
ZeroGUI::滑动开关(OBFUSCATE("忽略倒地"), &Settings.Aim.knocked);
ZeroGUI::滑动开关(OBFUSCATE("忽略人机"), &Settings.Aim.nobot);
break;
case 3://自瞄
ZeroGUI::滑动开关("初始化(静默瞄准)", &Settings.Aim.漏打自瞄);
ZeroGUI::SliderFloat(OBFUSCATE("平滑力度"), &XY, 1.0f, 10.0f, "%0.1f");
ZeroGUI::SliderFloat(OBFUSCATE("圈圈大小"), &Settings.Aim.fovsize, 0, 650.0, "%.1f");
ZeroGUI::Combobox(OBFUSCATE("锁定方式"), FVector2D{ 390,45 }, &Settings.Aim.location, "漏打智能优先锁定胸部", "漏打智能优先锁定头部", NULL);
ZeroGUI::Combobox(OBFUSCATE("触发方式"), FVector2D{ 390,45 }, &Settings.Aim.trigger, "开火", "同时", NULL);
ZeroGUI::滑动开关(OBFUSCATE("忽略倒地"), &Settings.Aim.knocked);
ZeroGUI::滑动开关(OBFUSCATE("忽略人机"), &Settings.Aim.nobot);
break;
case 4://内存

ZeroGUI::SameLine();
if (ZeroGUI::Button(OBFUSCATE("广角"), FVector2D(95, 30))) {
writedword(readValueL(UE4+0xDE24C70)+0x7C, 5);//广角
}
ZeroGUI::SameLine();

ZeroGUI::SameLine();
if (ZeroGUI::Button(OBFUSCATE("打击特效"), FVector2D(95, 30))) {
writefloat(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x4C8)+0x5A0)+0x10, 25); //特效
writefloat(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x4C8)+0x5A0)+0x50, 25); //特效
writefloat(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x4C8)+0x5A0)+0x90, 25); //特效
writefloat(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x4C8)+0x5A0)+0xD0, 25); //特效

writefloat(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x4C8)+0x5A0)+0x14, 8888); //特效
writefloat(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x4C8)+0x5A0)+0x54, 8888); //特效
writefloat(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x4C8)+0x5A0)+0x94, 8888); //特效
writefloat(readValueL(readValueL(readValueL(readValueL(UE4+0xDE24C70)+0x30)+0x4C8)+0x5A0)+0xD4, 8888); //特效
}


break;   
case 5://内存
ZeroGUI::Checkbox("烈焰古神", &烈焰古神);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("神羽恋人", &神羽恋人);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("秘渊领主", &果冻美化);

ZeroGUI::Checkbox("小丧尸", &小丧尸);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("大丧尸", &大丧尸);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("祖国人", &祖国人);

ZeroGUI::Checkbox("蓝木乃伊", &蓝木乃伊);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("明日香", &明日香美化);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("猴子美化", &猴子);

ZeroGUI::Checkbox("胖达头盔", &胖达头盔);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("隐藏头盔", &隐藏头盔);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("隐藏背包", &隐藏背包);

ZeroGUI::Checkbox("天使背包", &天使背包);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("冰霜核心M4", &冰霜M4);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("封印幽冥M4", &M4小丑);

ZeroGUI::Checkbox("机魂忍神M4", &M4武魂宗师);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("霓虹天后scar", &封印幽冥M4);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("龙吟妹控", &龙吟妹控);

ZeroGUI::Checkbox("风鸣神戟MG3", &风鸣神戟);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("冰霜播报", &冰霜核心);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("死噶播报", &死噶血魂);

ZeroGUI::Checkbox("星云播报", &星云力量);
ZeroGUI::SameLine();
ZeroGUI::Checkbox("魔力播报", &魔力结晶);

            if (ZeroGUI::Button("秒刷新开启",FVector2D(80, 30))) {

localPlayer->AvatarComponent2->OnRep_BodySlotStateChanged();
            }
if (ZeroGUI::Button(OBFUSCATE("过美化一秒"), FVector2D(95, 30))) {

writedword(UE4+0x7161538, -721215457);
writedword(UE4+0x7161548, 402653170);

}            
            
            break; 
            
}}}}
return orig_PostRender(ViewportClient, Canvas);
}

int (*orig_onInputEvent)(struct android_app *app, AInputEvent *inputEvent);
int onInputEvent(struct android_app *app, AInputEvent *inputEvent) {
    if (AInputEvent_getType(inputEvent) == AINPUT_EVENT_TYPE_KEY) {
        int32_t keyCode = AKeyEvent_getKeyCode(inputEvent);
        switch (keyCode) {
            case AKEYCODE_VOLUME_UP:
                IsOpen = true;
                break;
            case AKEYCODE_VOLUME_DOWN:
                IsOpen = false;
                break;
            default:
                break;
        }
    }
    ZeroGUI::onEvent(inputEvent, {(float)screenSizeX / (float)screenWidth, (float)screenSizeY / (float)screenHeight});
    return orig_onInputEvent(app, inputEvent);
}

#include "Tools/主线程.h"
