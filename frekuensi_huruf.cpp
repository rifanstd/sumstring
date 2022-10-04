#include <iostream>
#include <cstring>
using namespace std;

char alphabets[27] = "abcdefghijklmnopqrstuvwxyz";
int len_alp = 26;

struct Node {
	char huruf;
	Node *next;
};

Node *head;

void init(){
	head = NULL;
}

bool isEmpty(){
	if (head == NULL)
		return true;
	else
		return false;
}

void tambah_belakang(char huruf_baru){
	Node *baru, *bantu;
	baru = new Node;
	baru->next = NULL;
	baru->huruf = huruf_baru;

	if (isEmpty()){
		head = baru;
		head->next = NULL;
	}
	else {
		bantu = head;
		while (bantu->next != NULL){
			bantu = bantu->next;
		}
		bantu->next = baru;
	}
}

void cek_frek(){
	Node *bantu;
	for (int i = 0; i < len_alp; i++){
		int index_str = 0, index_arr = 0, simpan[100], count = 0;
		bantu = head;
		if (alphabets[i] == bantu->huruf){
			simpan[index_arr] = index_str;
			index_arr++;
			count++;
		}

		while (bantu != NULL){
			index_str++;
			bantu = bantu->next;
			if (bantu != NULL){
				if (alphabets[i] == bantu->huruf){
					simpan[index_arr] = index_str;
					index_arr++;
					count++;
				}
			}
		}

		if (count > 0){
			cout << alphabets[i] << ": " << count << " kali pada ";
			for (int i = 0; i < count; i++){
				cout << simpan[i] << ", ";
			}
			cout << endl;
		}
	}	
}

int main(){
	char str[200];
	int sub = 0;
	cin.getline(str,200,'\n');
	int length = strlen(str);

	if (length > 100){
		cout << "Masukkan melebihi 100 karakter" << endl;
		return 0;
	}
	else if (str[0] == '.'){
		cout << "Masukkan tidak boleh diawali karakter '.' (titik)" << endl;
		return 0;
	}

	for (int i = 0; i < length; i++){
		if (str[i] == ' '){
			for (int j = i; j < length-1; j++){
				str[j] = str[j+1];
			}
			sub++;
		}
	}

	length -= sub;

	init();

	for (int i = 0; i < length; i++){
		tambah_belakang(tolower(str[i]));
	}

	cek_frek();
	return 0;
}
