/*
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.0 of the PHP license,       |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_0.txt.                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Kazusuke Sasezaki <sasezaki@gmail.com>                      |
   +----------------------------------------------------------------------+
*/

/* $ Id: $ */ 

#include "php_constellation.h"

#if HAVE_CONSTELLATION

/* {{{ constellation_functions[] */
function_entry constellation_functions[] = {
	PHP_FE(constellation       , constellation_arg_info)
	{ NULL, NULL, NULL }
};
/* }}} */


/* {{{ constellation_module_entry
 */
zend_module_entry constellation_module_entry = {
	STANDARD_MODULE_HEADER,
	"constellation",
	constellation_functions,
	PHP_MINIT(constellation),     /* Replace with NULL if there is nothing to do at php startup   */ 
	PHP_MSHUTDOWN(constellation), /* Replace with NULL if there is nothing to do at php shutdown  */
	PHP_RINIT(constellation),     /* Replace with NULL if there is nothing to do at request start */
	PHP_RSHUTDOWN(constellation), /* Replace with NULL if there is nothing to do at request end   */
	PHP_MINFO(constellation),
	PHP_CONSTELLATION_VERSION, 
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_CONSTELLATION
ZEND_GET_MODULE(constellation)
#endif


/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(constellation)
{

	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(constellation)
{

	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(constellation)
{
	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_RSHUTDOWN_FUNCTION */
PHP_RSHUTDOWN_FUNCTION(constellation)
{
	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(constellation)
{
	php_printf("calc constellation\n");
	php_info_print_table_start();
	php_info_print_table_row(2, "Version",PHP_CONSTELLATION_VERSION " (stable)");
	php_info_print_table_row(2, "Released", "2011-09-30");
	php_info_print_table_row(2, "CVS Revision", "$Id: $");
	php_info_print_table_row(2, "Authors", "Kazusuke Sasezaki 'sasezaki@gmail.com' (lead)\n");
	php_info_print_table_end();
	/* add your stuff here */

}
/* }}} */


/* {{{ proto string constellation()
  calc constellation */
PHP_FUNCTION(constellation)
{

	long *birth = NULL;
	char *result = NULL;
	int birth_len = 0, result_len = 0;

	char *constellation = NULL;
	int constellation_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &birth, &birth_len) == FAILURE) {
		RETURN_FALSE;
	}

	if (birth < 101) {
		RETURN_FALSE;
	}
	if (birth > 1231) {
		RETURN_FALSE;
	}

	if (birth < 121) {
		constellation = "Capricornus";
	} else if (birth < 219) {
		constellation = "Aquarius";
	} else if (birth < 321) {
		constellation = "Pisces";
	} else if (birth < 420) {
		constellation = "Aries";
	} else if (birth < 521) {
		constellation = "Taurus";
	} else if (birth < 621) {
		constellation = "Gemini";
	} else if (birth < 722) {
		constellation = "Cancer";
	} else if (birth < 823) {
		constellation = "Leo";
	} else if (birth < 923) {
		constellation = "Virgo";
	} else if (birth < 1024) {
		constellation = "Libra";
	} else if (birth < 1122) {
		constellation = "Scorpio";
	} else if (birth < 1222) {
		constellation = "Sagittarius";
	} else {
		constellation = "Capricornus";
	}

	constellation_len = strlen(constellation);

	result = php_str_to_str(constellation, constellation_len, "", 0, "", 0, &result_len);

	RETVAL_STRING(result, 1);
	efree(result);

}
/* }}} constellation */

#endif /* HAVE_CONSTELLATION */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
