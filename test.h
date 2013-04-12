
#ifndef TEST_H_
#define TEST_H_

#include "npapi.h"
#include "npfunctions.h"
#include "npruntime.h"
#include "nptypes.h"
#include "plugin.h"

#ifndef HIBYTE
#define HIBYTE(x) ((((uint32_t)(x)) & 0xff00) >> 8)
#endif

#ifndef LOBYTE
#define LOBYTE(W) ((W) & 0xFF)
#endif

extern NPNetscapeFuncs NPNFuncs;

//******* NP_* Functions

NPError OSCALL NP_GetEntryPoints(NPPluginFuncs* pFuncs);
NPError NP_Initialize(NPNetscapeFuncs* bFuncs, NPPluginFuncs* pFuncs);
char* NP_GetPluginVersion();
const char* NP_GetMIMEDescription();
NPError NPP_Initialize(void);
NPError NP_GetValue(void* future, NPPVariable aVariable, void* aValue);
NPError NP_Shutdown();

//******* NPP_* Functions

NPError NPP_New(NPMIMEType pluginType, NPP instance, uint16_t mode, int16_t argc, char* argn[], char* argv[], NPSavedData* saved);
NPError NPP_Destroy(NPP instance, NPSavedData** save);
NPError NPP_SetWindow(NPP instance, NPWindow* window);
NPError NPP_NewStream(NPP instance, NPMIMEType type, NPStream* stream, NPBool seekable, uint16_t* stype);
NPError NPP_DestroyStream(NPP instance, NPStream* stream, NPReason reason);
int32_t NPP_WriteReady(NPP instance, NPStream* stream);
int32_t NPP_Write(NPP instance, NPStream* stream, int32_t offset, int32_t len, void* buffer);
   void NPP_StreamAsFile(NPP instance, NPStream* stream, const char* fname);
   void NPP_Print(NPP instance, NPPrint* platformPrint);
int16_t NPP_HandleEvent(NPP instance, void* event);
    void NPP_URLNotify(NPP instance, const char* URL, NPReason reason, void* notifyData);
NPError NPP_GetValue(NPP instance, NPPVariable variable, void *value);
NPError NPP_SetValue(NPP instance, NPNVariable variable, void *value);
NPObject *NPP_GetScriptableInstance(NPP instance);

//******* NPN_* Functions

void NPN_Version(int* plugin_major, int* plugin_minor, int* netscape_major, int* netscape_minor);
NPError NPN_GetURLNotify(NPP instance, const char *url, const char *target, void* notifyData);
NPError NPN_GetURL(NPP instance, const char *url, const char *target);
NPError NPN_PostURLNotify(NPP instance, const char* url, const char* window, uint32_t len, const char* buf, NPBool file, void* notifyData);
NPError NPN_PostURL(NPP instance, const char* url, const char* window, uint32_t len, const char* buf, NPBool file);
NPError NPN_RequestRead(NPStream* stream, NPByteRange* rangeList);
NPError NPN_NewStream(NPP instance, NPMIMEType type, const char* target, NPStream** stream);
int32_t NPN_Write(NPP instance, NPStream *stream, int32_t len, void *buffer);
NPError NPN_DestroyStream(NPP instance, NPStream* stream, NPError reason);
void NPN_Status(NPP instance, const char *message);
const char* NPN_UserAgent(NPP instance);
void* NPN_MemAlloc(uint32_t size);
void NPN_MemFree(void* ptr);
uint32_t NPN_MemFlush(uint32_t size);
void NPN_ReloadPlugins(NPBool reloadPages);
NPError NPN_GetValue(NPP instance, NPNVariable variable, void *value);
NPError NPN_SetValue(NPP instance, NPPVariable variable, void *value);
void NPN_InvalidateRect(NPP instance, NPRect *invalidRect);
void NPN_InvalidateRegion(NPP instance, NPRegion invalidRegion);
void NPN_ForceRedraw(NPP instance);
NPIdentifier NPN_GetStringIdentifier(const NPUTF8 *name);
void NPN_GetStringIdentifiers(const NPUTF8 **names, uint32_t nameCount, NPIdentifier *identifiers);
NPIdentifier NPN_GetStringIdentifier(int32_t intid);
bool NPN_IdentifierIsString(NPIdentifier identifier);
NPUTF8 *NPN_UTF8FromIdentifier(NPIdentifier identifier);
int32_t NPN_IntFromIdentifier(NPIdentifier identifier);
NPObject *NPN_CreateObject(NPP npp, NPClass *aClass);
NPObject *NPN_RetainObject(NPObject *obj);
void NPN_ReleaseObject(NPObject *obj);
bool NPN_Invoke(NPP npp, NPObject* obj, NPIdentifier methodName, const NPVariant *args, uint32_t argCount, NPVariant *result);
bool NPN_InvokeDefault(NPP npp, NPObject* obj, const NPVariant *args,  uint32_t argCount, NPVariant *result);
bool NPN_Evaluate(NPP npp, NPObject* obj, NPString *script,NPVariant *result);
bool NPN_GetProperty(NPP npp, NPObject* obj, NPIdentifier propertyName, NPVariant *result);
bool NPN_SetProperty(NPP npp, NPObject* obj, NPIdentifier propertyName, const NPVariant *value);
bool NPN_RemoveProperty(NPP npp, NPObject* obj, NPIdentifier propertyName);
bool NPN_Enumerate(NPP npp, NPObject *obj, NPIdentifier **identifier, uint32_t *count);
bool NPN_Construct(NPP npp, NPObject *obj, const NPVariant *args, uint32_t argCount, NPVariant *result);
bool NPN_HasProperty(NPP npp, NPObject* obj, NPIdentifier propertyName);
bool NPN_HasMethod(NPP npp, NPObject* obj, NPIdentifier methodName);
void NPN_ReleaseVariantValue(NPVariant *variant);
void NPN_SetException(NPObject* obj, const NPUTF8 *message);

//bool NPN_Invoke(NPP npp, NPObject *npobj, NPIdentifier methodName, const NPVariant *args, uint32_t argCount, NPVariant *result);

#endif /* TEST_H_ */
