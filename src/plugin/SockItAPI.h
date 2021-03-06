/**********************************************************
 Auto-generated SockItAPI.h

 \**********************************************************/

#ifndef H_SockItAPI
#define H_SockItAPI

#include <map>
#include <string>
#include <sstream>
#include <vector>

#include <boost/optional.hpp>
#include <boost/weak_ptr.hpp>

#include <stdint.h>

#include "BrowserHost.h"
#include "JSAPIAuto.h"

#include "SockIt.h"
#include "NetworkThread.h"

using std::map;
using std::string;
using std::vector;

/**
 * Exposes the plugin's API to the browser. Primarily auto-generated by FireBreath, but edited to add root methods
 * for the plugin and expose them to the javascript.
 *
 * 	@see http://www.firebreath.org/
 */
class SockItAPI: public FB::JSAPIAuto
{
	public:

		/**
		 * Constructor for the JSAPI object.  Registers root API methods for the plugin to be available to Javascript.
		 *
		 * 	@see FB::JSAPIAuto::registerMethod
		 * 	@see FB::JSAPIAuto::registerProperty
		 * 	@see FB::JSAPIAuto::registerEvent
		 */
		SockItAPI(const SockItPtr& plugin, const FB::BrowserHostPtr& host);

		/**
		 * @brief  Destructor.  Remember that this object will not be released until the browser is done with it; this
		 * 			will almost definitely be after the plugin is released.
		 */
		virtual ~SockItAPI();

		/**
		 * @brief  Gets a reference to the plugin that was passed in when the object was created.  If the plugin has
		 * 			already been released then this will throw a FB::script_error that will be translated into a javascript
		 * 			exception in the page.
		 */
		SockItPtr getPlugin();

		/**
		 * Creates a new <code>NetworkThread</code> object on which we can create new clients and servers.
		 *
		 * 	@return A shared pointer to a newly created <code>NetworkThread</code> object
		 */
		boost::shared_ptr<NetworkThread> create_thread();

		/**
		 * Creates a new TCP server on the default <code>NetworkThread</code>.
		 *
		 * 	@param	port		The port on which this new TCP server should listen
         * 	@param  options     The set of options passed in from Javascript.
		 * 	@return	A shared pointer to a newly created TCP server
		 */
		boost::shared_ptr<TcpServer> create_tcp_server(int port, boost::optional<map<string, string> > options);

		/**
		 * Creates a new TCP client on the default <code>NetworkThread</code>.
		 *
		 * 	@param	host	The hostname to which this TCP client will connect
		 * 	@param	port	The port on the remote host to which this client should connect
         * 	@param  options The set of options passed in from Javascript.
		 * 	@return	A shared pointer to a newly created TCP client
		 */
		boost::shared_ptr<TcpClient> create_tcp_client(const string & host, int port, 
                boost::optional<map<string, string> > options);

		/**
		 * Creates a new UDP server on the default <code>NetworkThread</code>.
		 *
		 * 	@param	port			The port on which this new UDP server should listen
         * 	@param  options         The set of options passed in from Javascript.
		 * 	@return	A shared pointer to a newly created UDP server
		 */
		boost::shared_ptr<UdpServer> create_udp_server(int port, boost::optional<map<string, string> > options);

		/**
		 * Creates a new UDP client on the default <code>NetworkThread</code>.
		 *
		 * 	@param	host	The hostname to which this UDP client will connect
		 * 	@param	port	The port on the remote host to which this client should connect
         * 	@param  options The set of options passed in from Javascript.
		 * 	@return	A shared pointer to a newly created UDP client
		 */
		boost::shared_ptr<UdpClient> create_udp_client(const string &host, int port,
                boost::optional<map<string, string> > options);

		/**
		 * Utility function for converting an array of integers, assumed to hexadecimal numbers, to a string.
		 *
		 * 	@param	bytes	The bytes of data to be converted into a string
		 */
		binary convert_to_binary(const vector<byte> bytes);

		/**
		 * Utility function for converting a string, assumed to be binary data returned from <code>convert_to_binary</code>.
		 *
		 * 	@param	data	The (binary) data to be converted to an array of characters
		 */
		FB::VariantList convert_from_binary(binary data);

	private:

		/**
		 * The default network thread used if no thread is explicitly created.
		 */
		NetworkThread default_thread;

		/**
		 * A handle on the plugin object itself.
		 */
		SockItWeakPtr m_plugin;

		/**
		 * A handle on the browser to gather information if necessary.
		 */
		FB::BrowserHostPtr m_host;
};

#endif // H_SockItAPI
