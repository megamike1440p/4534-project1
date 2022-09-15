#include cipher.hpp

class ciphertest
{
	public:
		ciphertest(){
			cipher("data") cipherTest;
			if(cipherTest.encrypt() == "moge"){cout << "TEST PASSED: data = moge.";}
			else {cout << "TEST FAIL.";}
		}
};
