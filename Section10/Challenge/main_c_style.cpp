#include <iostream>
#include <cstring>

using namespace std;

int main() {
	/*
	 * Printable characters:
	 * 	From 32 (' ') to 126 ('~')
	 */

	const int encryption_offset {13};

	char original_message[50] {};

	cout << "Please enter a message: ";
	cin.getline(original_message, 50);

	if (original_message[0] == '\0') {
		cout << "You entered an empty message. Bye!" << endl;
		return 0;
	}

	size_t message_length {};
	while (original_message[message_length] != '\0') {
		++message_length;
	}

	char encrypted_message[message_length] {};
	for (char c : original_message) {
		char encrypted_c[2] {};
		if (c + encryption_offset <= '~') {
			encrypted_c[0] = c + encryption_offset;
		} else {
			int offset {};
			offset = (c + encryption_offset) - '~' - 1;
			encrypted_c[0] = ' ' + offset;
		}
		strcat(encrypted_message, encrypted_c);
	}

	cout << "\nEncrypted message: " << encrypted_message << endl;

	char decrypted_message[message_length] {};
	for (char c : encrypted_message) {
		char decrypted_c[2] {};
		if (c - encryption_offset >= ' ') {
			decrypted_c[0] = c - encryption_offset;
		} else {
			int offset {};
			offset = (c - encryption_offset) - ' ' + 1;
			decrypted_c[0] = '~' + offset;
		}
		strcat(decrypted_message, decrypted_c);
	}

	cout << "\nDecrypted message: " << decrypted_message << endl;

	if (strcmp(original_message, decrypted_message) == 0) {
		cout << "\nThe strings are the same! Yay!" << endl;
	} else {
		cout << "\nThe encrypt-decrypt proccess went wrong... Ups!" << endl;
	}

	cout << endl;
	return 0;
}
