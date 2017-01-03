#ifndef STDAFX_H
#define STDAFX_H
#define _CRT_SECURE_NO_WARNINGS
#define  BOOST_FILESYSTEM_NO_DEPRECATE

#include <stdio.h>
#include <tchar.h>


/*
*
* general includes
*
*/
#include <iostream>
#include <string>
#include <memory>
// make hash_path::get_hash_digest member function thread safe.
#include <mutex>
#include <algorithm>
#include <vector>
#include <utility>
#include <iterator>
#include <time.h> // for runtime http://www.cplusplus.com/forum/beginner/14666/#msg71908
#include <iostream>                         // for std::cout
#include <utility>                          // for std::pair
#include <algorithm>                        // for std::for_each

/*
* windows headers
*/
#include <conio.h> // used for delayed exit http://www.cplusplus.com/forum/general/16335/#msg81524


/*
*
*Boost includes
*
*/
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/thread/thread.hpp> // for sleeping at exit
#include <boost/function.hpp> // for comparison hash_path overloads

/*
*
*OpenSsl includes
*
*/
#include <openssl/sha.h>


/*
 *
 * Qt includes
 *
 */
#include <QObject>
#include <QString>
#include <QList>

#include "hash_path.h"
#include "gc_file_system.h"


#endif // STDAFX_H
