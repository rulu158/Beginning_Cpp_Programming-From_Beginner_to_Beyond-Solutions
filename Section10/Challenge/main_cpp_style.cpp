#include <iostream>
#include <string>

using namespace std;

int main() {
	/*
	 * Printable characters:
	 * 	From 32 (' ') to 126 ('~')
	 */

	const int encryption_offset {13};

	string original_message {};

	cout << "Please enter a message: ";
	getline(cin, original_message);

	if (original_message.length() == 0) {
		cout << "You entered an empty message. Bye!" << endl;
		return 0;
	}

	string encrypted_message {};
	for (char c : original_message) {
		char encrypted_c {};
		if (c + encryption_offset <= '~') {
			encrypted_c = c + encryption_offset;
		} else {
			int offset {};
			offset = (c + encryption_offset) - '~' - 1;
			encrypted_c = ' ' + offset;
		}
		encrypted_message += encrypted_c;
	}

	cout << "\nEncrypted message: " << encrypted_message << endl;

	string decrypted_message {};
	for (char c : encrypted_message) {
		char decrypted_c {};
		if (c - encryption_offset >= ' ') {
			decrypted_c = c - encryption_offset;
		} else {
			int offset {};
			offset = (c - encryption_offset) - ' ' + 1;
			decrypted_c = '~' + offset;
		}
		decrypted_message += decrypted_c;
	}

	cout << "\nDecrypted message: " << decrypted_message << endl;

	if (original_message == decrypted_message) {
		cout << "\nThe strings are the same! Yay!" << endl;
	} else {
		cout << "\nThe encrypt-decrypt proccess went wrong... Ups!" << endl;
	}

	cout << endl;
	return 0;
}
