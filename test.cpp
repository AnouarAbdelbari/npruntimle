
#include "test.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define PLUGIN_NAME        "test Plugin v1.4"
#define PLUGIN_DESCRIPTION "Scriptable test Plugin"

// NPNetscapeFuncs : structure involved in registration
NPNetscapeFuncs sBrowserFuncs;

NPError OSCALL NP_GetEntryPoints(NPPluginFuncs* pFuncs)
{
    if(pFuncs == NULL)
        return NPERR_INVALID_FUNCTABLE_ERROR;

    if(pFuncs->size < sizeof(NPPluginFuncs))
        return NPERR_INVALID_FUNCTABLE_ERROR;

    pFuncs->version       = (NP_VERSION_MAJOR << 8) | NP_VERSION_MINOR;
    pFuncs->newp          = NPP_New;
    pFuncs->destroy       = NPP_Destroy;
    pFuncs->setwindow     = NPP_SetWindow;
    pFuncs->newstream     = NPP_NewStream;
    pFuncs->destroystream = NPP_DestroyStream;
    pFuncs->asfile        = NPP_StreamAsFile;
    pFuncs->writeready    = NPP_WriteReady;
    pFuncs->write         = NPP_Write;
    pFuncs->print         = NPP_Print;
    pFuncs->event         = NPP_HandleEvent;
    pFuncs->urlnotify     = NPP_URLNotify;
    pFuncs->getvalue      = NPP_GetValue;
    pFuncs->setvalue      = NPP_SetValue;
    pFuncs->javaClass     = NULL;

    return NPERR_NO_ERROR;
}

// NP_Initialize : Provides global initialization for a plug-in.
NPError NP_Initialize(NPNetscapeFuncs* bFuncs, NPPluginFuncs* pFuncs)
{

  if(bFuncs == NULL)
	        return NPERR_INVALID_FUNCTABLE_ERROR;

	    if(HIBYTE(bFuncs->version) > NP_VERSION_MAJOR)
	        return NPERR_INCOMPATIBLE_VERSION_ERROR;

	    if(bFuncs->size < sizeof(NPNetscapeFuncs))
	        return NPERR_INVALID_FUNCTABLE_ERROR;

	    //The NPNestscapeFuncs structure contains pointers to browser functions that can be called by the plugin.
	    // sBrowserFuncs ====> NPN_* Functions

	    sBrowserFuncs.size                    = bFuncs->size;
	    sBrowserFuncs.version                 = bFuncs->version;
	    sBrowserFuncs.geturlnotify            = bFuncs->geturlnotify;
	    sBrowserFuncs.geturl                  = bFuncs->geturl;
	    sBrowserFuncs.posturlnotify           = bFuncs->posturlnotify;
	    sBrowserFuncs.posturl                 = bFuncs->posturl;
	    sBrowserFuncs.requestread             = bFuncs->requestread;
	    sBrowserFuncs.newstream               = bFuncs->newstream;
	    sBrowserFuncs.write                   = bFuncs->write;
	    sBrowserFuncs.destroystream           = bFuncs->destroystream;
	    sBrowserFuncs.status                  = bFuncs->status;
	    sBrowserFuncs.uagent                  = bFuncs->uagent;
	    sBrowserFuncs.memalloc                = bFuncs->memalloc;
	    sBrowserFuncs.memfree                 = bFuncs->memfree;
	    sBrowserFuncs.memflush                = bFuncs->memflush;
	    sBrowserFuncs.reloadplugins           = bFuncs->reloadplugins;
	    sBrowserFuncs.getJavaEnv              = bFuncs->getJavaEnv;
	    sBrowserFuncs.getJavaPeer             = bFuncs->getJavaPeer;
	    sBrowserFuncs.getvalue                = bFuncs->getvalue;
	    sBrowserFuncs.setvalue                = bFuncs->setvalue;
	    sBrowserFuncs.invalidaterect          = bFuncs->invalidaterect;
	    sBrowserFuncs.invalidateregion        = bFuncs->invalidateregion;
	    sBrowserFuncs.forceredraw             = bFuncs->forceredraw;
	    sBrowserFuncs.getstringidentifier     = bFuncs->getstringidentifier;
	    sBrowserFuncs.getstringidentifiers    = bFuncs->getstringidentifiers;
	    sBrowserFuncs.getintidentifier        = bFuncs->getintidentifier;
	    sBrowserFuncs.identifierisstring      = bFuncs->identifierisstring;
	    sBrowserFuncs.utf8fromidentifier      = bFuncs->utf8fromidentifier;
	    sBrowserFuncs.intfromidentifier       = bFuncs->intfromidentifier;
	    sBrowserFuncs.createobject            = bFuncs->createobject;
	    sBrowserFuncs.retainobject            = bFuncs->retainobject;
	    sBrowserFuncs.releaseobject           = bFuncs->releaseobject;
	    sBrowserFuncs.invoke                  = bFuncs->invoke;
	    sBrowserFuncs.invokeDefault           = bFuncs->invokeDefault;
	    sBrowserFuncs.evaluate                = bFuncs->evaluate;
	    sBrowserFuncs.getproperty             = bFuncs->getproperty;
	    sBrowserFuncs.setproperty             = bFuncs->setproperty;
	    sBrowserFuncs.removeproperty          = bFuncs->removeproperty;
	    sBrowserFuncs.hasproperty             = bFuncs->hasproperty;
	    sBrowserFuncs.hasmethod               = bFuncs->hasmethod;
	    sBrowserFuncs.releasevariantvalue     = bFuncs->releasevariantvalue;
	    sBrowserFuncs.setexception            = bFuncs->setexception;

	#ifdef XP_UNIX
	    /*
	    * Set up the plugin function table that Netscape will use to
	    * call us.  Netscape needs to know about our version and size
	    * and have a UniversalProcPointer for every function we
	    * implement.
	    */
	    pFuncs->version    = (NP_VERSION_MAJOR << 8) + NP_VERSION_MINOR;
	    pFuncs->size       = sizeof(NPPluginFuncs);
	    pFuncs->newp       = NPP_New;
	    pFuncs->destroy    = NPP_Destroy;
	    pFuncs->setwindow  = NPP_SetWindow;
	    pFuncs->newstream  = NPP_NewStream;
	    pFuncs->destroystream = NPP_DestroyStream;
	    pFuncs->asfile     = NPP_StreamAsFile;
	    pFuncs->writeready = NPP_WriteReady;
	    pFuncs->write      = NPP_Write;
	    pFuncs->print      = NPP_Print;
	    pFuncs->urlnotify  = NPP_URLNotify;
	    pFuncs->event      = NULL;
	    pFuncs->getvalue   = NPP_GetValue;
	#ifdef OJI
	    pluginFuncs->javaClass  = NPP_GetJavaClass();
	#endif

	    NPP_Initialize();
	#endif

	    return NPERR_NO_ERROR;

}

// undocumented functions
char* NP_GetPluginVersion()
{
  return "1.1";
}

// NP_GetMIMEDescription : return the MIME type
const char* NP_GetMIMEDescription()
{
  return "application/test-plugin:Extension:Description";
}

NPError NPP_Initialize(void)
{
  return NPERR_NO_ERROR;
}




// NP_GetValue : Allows the browser to query the plug-in for information.
NPError
NP_GetValue(void* future, NPPVariable variable, void* value)
{
/*		  NPError rv = NPERR_NO_ERROR;

		  CPlugin * plugin = (CPlugin *)instance->pdata;
		  if(plugin == NULL)
		    return NPERR_GENERIC_ERROR;

		  switch (variable) {
		  case NPPVpluginNameString:
		    *((const char **)value) = PLUGIN_NAME;
		    break;
		  case NPPVpluginDescriptionString:
		    *((const char **)value) = PLUGIN_DESCRIPTION;
		    break;
		  case NPPVpluginScriptableNPObject:
		    *(NPObject **)value = plugin->GetScriptableObject();
		    break;
		  default:
		    rv = NPERR_GENERIC_ERROR;
		    break;
		  }
		  return rv;
*/

	return NPP_GetValue((NPP_t *)future, variable, value);
}

// NP_Shutdown : Provides global deinitialization for a plug-in.
NPError
OSCALL NP_Shutdown()
{
  return NPERR_NO_ERROR; // No errors occurred
}

// here the plugin creates an instance of our CPlugin object which
// will be associated with this newly created plugin instance and
// will do all the neccessary job
NPError NPP_New(NPMIMEType pluginType,
                NPP instance,
                uint16_t mode,
                int16_t argc,
                char* argn[],
                char* argv[],
                NPSavedData* saved)
{
	//return NPERR_NO_ERROR;
  if(instance == NULL)
    return NPERR_INVALID_INSTANCE_ERROR;

  NPError rv = NPERR_NO_ERROR;

  CPlugin * pPlugin = new CPlugin(instance);
  if(pPlugin == NULL)
    return NPERR_OUT_OF_MEMORY_ERROR;

  //instance->pdata = (void *)pPlugin;
  	instance->pdata = pPlugin;
  return rv;
}

// NPP_Destroy : Deletes a specific instance of a plug-in.
NPError NPP_Destroy(NPP instance, NPSavedData** save)
{
	if(instance == NULL)
	    return NPERR_INVALID_INSTANCE_ERROR;

	  NPError rv = NPERR_NO_ERROR;

	  CPlugin * pPlugin = (CPlugin *)instance->pdata;
	  if(pPlugin != NULL) {
	    pPlugin->shut();
	    delete pPlugin;
	  }
	  return rv;
}

// during this call we know when the plugin window is ready or
// is about to be destroyed so we can do some gui specific
// initialization and shutdown
NPError NPP_SetWindow (NPP instance, NPWindow* pNPWindow)
{
  if(instance == NULL)
    return NPERR_INVALID_INSTANCE_ERROR;

  NPError rv = NPERR_NO_ERROR;

  if(pNPWindow == NULL)
    return NPERR_GENERIC_ERROR;

  CPlugin * pPlugin = (CPlugin *)instance->pdata;

  if(pPlugin == NULL)
    return NPERR_GENERIC_ERROR;

  if(!pPlugin->isInitialized()){
	 if(!pPlugin->init(pNPWindow)){
		 return NPERR_MODULE_LOAD_FAILED_ERROR;
	 }
 }


  return rv;
}

NPError NPP_NewStream(NPP instance, NPMIMEType type, NPStream* stream, NPBool seekable, uint16_t* stype)
{
	if(instance == NULL)
	    return NPERR_INVALID_INSTANCE_ERROR;

	  NPError rv = NPERR_NO_ERROR;
	  return rv;
}

NPError NPP_DestroyStream(NPP instance, NPStream* stream, NPReason reason)
{
	if(instance == NULL)
	    return NPERR_INVALID_INSTANCE_ERROR;

	  NPError rv = NPERR_NO_ERROR;
	  return rv;
}

int32_t NPP_WriteReady(NPP instance, NPStream* stream)
{
	 if(instance == NULL)
	    return NPERR_INVALID_INSTANCE_ERROR;

	  int32_t rv = 0x0fffffff;
	  return rv;
}

int32_t NPP_Write(NPP instance, NPStream* stream, int32_t offset, int32_t len, void* buffer)
{
	  if(instance == NULL)
	    return NPERR_INVALID_INSTANCE_ERROR;

	  int32_t rv = len;
	  return rv;
}

void NPP_StreamAsFile(NPP instance, NPStream* stream, const char* fname)
{
	if(instance == NULL)
	    return;
}

void NPP_Print(NPP instance, NPPrint* platformPrint)
{
	if(instance == NULL)
	    return;
}

int16_t NPP_HandleEvent(NPP instance, void* event)
{
	if(instance == NULL)
	    return 0;

	  int16_t rv = 0;
	  CPlugin * pPlugin = (CPlugin *)instance->pdata;
	  if (pPlugin)
	    rv = pPlugin->handleEvent(event);

	  return rv;
}

void NPP_URLNotify(NPP instance, const char* URL, NPReason reason, void* notifyData)
{
	if(instance == NULL)
	    return;
}

// ==============================
// ! Scriptability related code !
// ==============================
//
// here the plugin is asked by Mozilla to tell if it is scriptable
// we should return a valid interface id and a pointer to
// nsScriptablePeer interface which we should have implemented
// and which should be defined in the corressponding *.xpt file
// in the bin/components folder
NPError
NPP_GetValue(NPP instance, NPPVariable variable, void *value)
{

	  NPError rv = NPERR_NO_ERROR;

   CPlugin * plugin = (CPlugin *)instance->pdata;
	 if(plugin == NULL)
	   return NPERR_GENERIC_ERROR;

	  switch (variable) {
	  case NPPVpluginNameString:
	    *((const char **)value) = PLUGIN_NAME;
	    break;
	  case NPPVpluginDescriptionString:
	    *((const char **)value) = PLUGIN_DESCRIPTION;
	    break;
	  case NPPVpluginScriptableNPObject:
	  *(NPObject **)value = plugin->GetScriptableObject();
    break;
	  default:
	    rv = NPERR_GENERIC_ERROR;
	    break;
	  }
	  return rv;
}

NPError NPP_SetValue(NPP instance, NPNVariable variable, void *value)
{
	    if(instance == NULL)
	      return NPERR_INVALID_INSTANCE_ERROR;

	    NPError rv = NPERR_NO_ERROR;
	    return rv;
}
/**/
NPObject *NPP_GetScriptableInstance(NPP instance)
{
  if(!instance)
    return 0;

  NPObject *npobj = 0;
  CPlugin * pPlugin = (CPlugin *)instance->pdata;
  if (pPlugin)
    npobj = pPlugin->GetScriptableObject();

  return npobj;
}
/**/





void NPN_Version(int* plugin_major, int* plugin_minor, int* netscape_major, int* netscape_minor)
{
    *plugin_major   = NP_VERSION_MAJOR;
    *plugin_minor   = NP_VERSION_MINOR;
    *netscape_major = HIBYTE(NPNFuncs.version);
    *netscape_minor = LOBYTE(NPNFuncs.version);
}

NPError NPN_GetURLNotify(NPP instance, const char *url, const char *target, void* notifyData)
{
    int navMinorVers = NPNFuncs.version & 0xFF;
    NPError rv = NPERR_NO_ERROR;

    if( navMinorVers >= NPVERS_HAS_NOTIFICATION )
        rv = NPNFuncs.geturlnotify(instance, url, target, notifyData);
    else
        rv = NPERR_INCOMPATIBLE_VERSION_ERROR;

    return rv;
}

NPError NPN_GetURL(NPP instance, const char *url, const char *target)
{
    NPError rv = NPNFuncs.geturl(instance, url, target);
    return rv;
}

NPError NPN_PostURLNotify(NPP instance, const char* url, const char* window, uint32_t len, const char* buf, NPBool file, void* notifyData)
{
    int navMinorVers = NPNFuncs.version & 0xFF;
    NPError rv = NPERR_NO_ERROR;

    if( navMinorVers >= NPVERS_HAS_NOTIFICATION )
        rv = NPNFuncs.posturlnotify(instance, url, window, len, buf, file, notifyData);
    else
        rv = NPERR_INCOMPATIBLE_VERSION_ERROR;

    return rv;
}

NPError NPN_PostURL(NPP instance, const char* url, const char* window, uint32_t len, const char* buf, NPBool file)
{
    NPError rv = NPNFuncs.posturl(instance, url, window, len, buf, file);
    return rv;
}

NPError NPN_RequestRead(NPStream* stream, NPByteRange* rangeList)
{
    NPError rv = NPNFuncs.requestread(stream, rangeList);
    return rv;
}

NPError NPN_NewStream(NPP instance, NPMIMEType type, const char* target, NPStream** stream)
{
    int navMinorVersion = NPNFuncs.version & 0xFF;

    NPError rv = NPERR_NO_ERROR;

    if( navMinorVersion >= NPVERS_HAS_STREAMOUTPUT )
        rv = NPNFuncs.newstream(instance, type, target, stream);
    else
        rv = NPERR_INCOMPATIBLE_VERSION_ERROR;

    return rv;
}

int32_t NPN_Write(NPP instance, NPStream *stream, int32_t len, void *buffer)
{
    int navMinorVersion = NPNFuncs.version & 0xFF;
    int32_t rv = 0;

    if( navMinorVersion >= NPVERS_HAS_STREAMOUTPUT )
        rv = NPNFuncs.write(instance, stream, len, buffer);
    else
        rv = -1;

    return rv;
}

NPError NPN_DestroyStream(NPP instance, NPStream* stream, NPError reason)
{
    int navMinorVersion = NPNFuncs.version & 0xFF;
    NPError rv = NPERR_NO_ERROR;

    if( navMinorVersion >= NPVERS_HAS_STREAMOUTPUT )
        rv = NPNFuncs.destroystream(instance, stream, reason);
    else
        rv = NPERR_INCOMPATIBLE_VERSION_ERROR;

    return rv;
}

void NPN_Status(NPP instance, const char *message)
{
    NPNFuncs.status(instance, message);
}

const char* NPN_UserAgent(NPP instance)
{
    const char * rv = NULL;
    rv = NPNFuncs.uagent(instance);
    return rv;
}

void* NPN_MemAlloc(uint32_t size)
{
    void * rv = NULL;
    rv = NPNFuncs.memalloc(size);
    return rv;
}

void NPN_MemFree(void* ptr)
{
    NPNFuncs.memfree(ptr);
}

uint32_t NPN_MemFlush(uint32_t size)
{
    uint32_t rv = NPNFuncs.memflush(size);
    return rv;
}

void NPN_ReloadPlugins(NPBool reloadPages)
{
    NPNFuncs.reloadplugins(reloadPages);
}

NPError NPN_GetValue(NPP instance, NPNVariable variable, void *value)
{
    NPError rv = NPNFuncs.getvalue(instance, variable, value);
    return rv;
}

NPError NPN_SetValue(NPP instance, NPPVariable variable, void *value)
{
    NPError rv = NPNFuncs.setvalue(instance, variable, value);
    return rv;
}

void NPN_InvalidateRect(NPP instance, NPRect *invalidRect)
{
    NPNFuncs.invalidaterect(instance, invalidRect);
}

void NPN_InvalidateRegion(NPP instance, NPRegion invalidRegion)
{
    NPNFuncs.invalidateregion(instance, invalidRegion);
}

void NPN_ForceRedraw(NPP instance)
{
    NPNFuncs.forceredraw(instance);
}

NPIdentifier NPN_GetStringIdentifier(const NPUTF8 *name)
{
    return NPNFuncs.getstringidentifier(name);
}

void NPN_GetStringIdentifiers(const NPUTF8 **names, uint32_t nameCount,
                              NPIdentifier *identifiers)
{
    return NPNFuncs.getstringidentifiers(names, nameCount, identifiers);
}

NPIdentifier NPN_GetStringIdentifier(int32_t intid)
{
    return NPNFuncs.getintidentifier(intid);
}

bool NPN_IdentifierIsString(NPIdentifier identifier)
{
    return NPNFuncs.identifierisstring(identifier);
}

NPUTF8 *NPN_UTF8FromIdentifier(NPIdentifier identifier)
{
    return NPNFuncs.utf8fromidentifier(identifier);
}

int32_t NPN_IntFromIdentifier(NPIdentifier identifier)
{
    return NPNFuncs.intfromidentifier(identifier);
}

NPObject *NPN_CreateObject(NPP npp, NPClass *aClass)
{
    return NPNFuncs.createobject(npp, aClass);
}

NPObject *NPN_RetainObject(NPObject *obj)
{
    return NPNFuncs.retainobject(obj);
}

void NPN_ReleaseObject(NPObject *obj)
{
    return NPNFuncs.releaseobject(obj);
}

bool NPN_Invoke(NPP npp, NPObject* obj, NPIdentifier methodName,
                const NPVariant *args, uint32_t argCount, NPVariant *result)
{
    return NPNFuncs.invoke(npp, obj, methodName, args, argCount, result);
}

bool NPN_InvokeDefault(NPP npp, NPObject* obj, const NPVariant *args,
                       uint32_t argCount, NPVariant *result)
{
    return NPNFuncs.invokeDefault(npp, obj, args, argCount, result);
}

bool NPN_Evaluate(NPP npp, NPObject* obj, NPString *script,
                  NPVariant *result)
{
    return NPNFuncs.evaluate(npp, obj, script, result);
}

bool NPN_GetProperty(NPP npp, NPObject* obj, NPIdentifier propertyName,
                     NPVariant *result)
{
    return NPNFuncs.getproperty(npp, obj, propertyName, result);
}

bool NPN_SetProperty(NPP npp, NPObject* obj, NPIdentifier propertyName,
                     const NPVariant *value)
{
    return NPNFuncs.setproperty(npp, obj, propertyName, value);
}

bool NPN_RemoveProperty(NPP npp, NPObject* obj, NPIdentifier propertyName)
{
    return NPNFuncs.removeproperty(npp, obj, propertyName);
}

bool NPN_Enumerate(NPP npp, NPObject *obj, NPIdentifier **identifier,
                   uint32_t *count)
{
    return NPNFuncs.enumerate(npp, obj, identifier, count);
}

bool NPN_Construct(NPP npp, NPObject *obj, const NPVariant *args,
                   uint32_t argCount, NPVariant *result)
{
    return NPNFuncs.construct(npp, obj, args, argCount, result);
}

bool NPN_HasProperty(NPP npp, NPObject* obj, NPIdentifier propertyName)
{
    return NPNFuncs.hasproperty(npp, obj, propertyName);
}

bool NPN_HasMethod(NPP npp, NPObject* obj, NPIdentifier methodName)
{
    return NPNFuncs.hasmethod(npp, obj, methodName);
}

void NPN_ReleaseVariantValue(NPVariant *variant)
{
    NPNFuncs.releasevariantvalue(variant);
}

void NPN_SetException(NPObject* obj, const NPUTF8 *message)
{
    NPNFuncs.setexception(obj, message);
}
