#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool  compare (string name1, string name2) {
	//converting the two names into lower case
	transform(name1.begin(), name1.end(), name1.begin(), ::tolower);
	transform(name2.begin(), name2.end(), name2.begin(), ::tolower);
	//comparing the two names
	for (int i = 0; i < name1.size(); i++) {
			if(name1[i] !=name2[i])
				return name1[i] < name2[i];
	}
}
void baisedSort(vector<string>& songsList) {
	int untitledSongsPostion = 0;
	//counting and putting untitled songs in the beginning
	for (int i = 0; i < songsList.size(); i++) {
		if (songsList[i] == "untitled" || songsList[i] == "Untitled") {
			string temp = songsList[untitledSongsPostion];
			songsList[untitledSongsPostion] = songsList[i];
			songsList[i] = temp;
			untitledSongsPostion++;
		}
	}

	//sorting the other songs

	for (int i = 1, j; i < songsList.size(); i++) {
		string temp = songsList[i];
		for (j = i; j > untitledSongsPostion && compare(temp , songsList[j - 1]); j--)
			songsList[j] = songsList[j - 1];

		songsList[j] = temp;
	}
	}

int main()
{
vector <string>songs={"bbb","untitled","aaa","untitled","ccc"};
baisedSort(songs);
    for(int i=0;i<songs.size();i++){
        cout<<songs[i]<<endl;
    }
}

