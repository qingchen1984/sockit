/**********************************************************
 Auto-generated SockIt.h

 This file contains the auto-generated main plugin object
 implementation for the SockIt project

 \**********************************************************/
#ifndef H_SockItPLUGIN
#define H_SockItPLUGIN

#include "PluginWindow.h"
#include "PluginEvents/MouseEvents.h"
#include "PluginEvents/AttachedEvent.h"
#include "PluginCore.h"

FB_FORWARD_PTR(SockIt)

#include "Logger.h"

/**
 * The root plugin object, auto-generated by FireBreath.
 *
 *	@see http://www.firebreath.org/
 */
class SockIt: public FB::PluginCore
{
	public:
		/**
		 * Performs one-time global initialization of the plugin. This should only be called once per process.
		 *
		 *	@fn SockIt::StaticInitialize()
		 * 	@brief  Called from PluginFactory::globalPluginInitialize()
		 * 	@see FB::FactoryBase::globalPluginInitialize
		 */
		static void StaticInitialize();

		/**
		 * Performs one-time global de-initialization of the plugin. This should be called just before
		 * 	the plugin library is unloaded
		 *
		 *	@fn SockIt::StaticDeinitialize()
		 *	@brief  Called from PluginFactory::globalPluginDeinitialize()
		 * 	@see FB::FactoryBase::globalPluginDeinitialize
		 */
		static void StaticDeinitialize();

	public:

		/**
		 * @brief  SockIt constructor. At this point, the API is not yet available, nor is the window.
		 */
		SockIt();

		/**
		 * @brief  SockIt destructor.
		 *
		 *	Tell the host to free the retained JSAPI objects unless the root JSAPI object is referenced
		 *	somewhere else, it will be released here.
		 */
		virtual ~SockIt();

	public:

		/**
		 * When this is called, the BrowserHost is attached, the JSAPI object is created, and we are ready
		 * to interact with the page and such.  The PluginWindow may or may not have already fire the AttachedEvent
		 * at this point.
		 */
		void onPluginReady();

		/**
		 * This will be called when it is time for the plugin to shut down; any threads or anything else that may hold a
		 * shared_ptr to this object should be released here so that this object can be safely destroyed. This is the last
		 * point that shared_from_this and weak_ptr references to this object will be valid.
		 */
		void shutdown();

		/**
		 * @brief  Creates an instance of the JSAPI object that provides the primary Javascript interface.
		 */
		virtual FB::JSAPIPtr createJSAPI();

		/**
		 * Tells the browser whether or not this plugin should have a window associated with it.
		 */
		virtual bool isWindowless()
		{
			return false;
		}

		BEGIN_PLUGIN_EVENT_MAP()
		EVENTTYPE_CASE(FB::MouseDownEvent, onMouseDown, FB::PluginWindow)
		EVENTTYPE_CASE(FB::MouseUpEvent, onMouseUp, FB::PluginWindow)
		EVENTTYPE_CASE(FB::MouseMoveEvent, onMouseMove, FB::PluginWindow)
		EVENTTYPE_CASE(FB::MouseMoveEvent, onMouseMove, FB::PluginWindow)
		EVENTTYPE_CASE(FB::AttachedEvent, onWindowAttached, FB::PluginWindow)
		EVENTTYPE_CASE(FB::DetachedEvent, onWindowDetached, FB::PluginWindow)
		END_PLUGIN_EVENT_MAP()

		/** BEGIN EVENTDEF -- DON'T CHANGE THIS LINE **/
		virtual bool onMouseDown(FB::MouseDownEvent *evt, FB::PluginWindow *);
		virtual bool onMouseUp(FB::MouseUpEvent *evt, FB::PluginWindow *);
		virtual bool onMouseMove(FB::MouseMoveEvent *evt, FB::PluginWindow *);
		virtual bool onWindowAttached(FB::AttachedEvent *evt, FB::PluginWindow *);
		virtual bool onWindowDetached(FB::DetachedEvent *evt, FB::PluginWindow *);
		/** END EVENTDEF -- DON'T CHANGE THIS LINE **/
};

#endif

