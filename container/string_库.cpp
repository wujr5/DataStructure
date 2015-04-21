#include<iostream>
#include<string>
#include<stdlib.h>
#include<cstring>
using namespace std;

int main() {
	string str;
	
	//str.append(), s.begin(), s.end()
	string s = "wujiarong ";
	str.append(s);//add "wujiarong "
	str.append(s, 5, 5);//add "rong "
	str.append("is a good student.", 3);//add "is "
	str.append("a ");//add "a "
	str.append(10, '.'); //add ".........."
	str.append(s.begin(), s.end());//add "wujiarong "
	cout << str << endl;
	
	//str.clear()
	str.clear();
	
	//str.assign()
	s = "wujiarong ";
	str.assign(s);//"wujiarong "
	str.assign(s, 2, 3);//"jia"
	str.assign("program is cool", 7);//"program"
	str.assign("wujiarong");//"wujiarong"
	str.assign(10, '*'); //"**********"
	str.assign(s.begin(), s.end());
	cout << str << endl;
	
	//str.at(), str.length()
	for (int i = 0; i < str.length(); i++) {
		cout << str.at(i);
	}
	cout << endl;
	
	//str.size(), str.capacity(), str.max_size()
	str.size();
	str.length();
	str.capacity();
	str.max_size();
	
	//str.compare()
	s = "green apple";
	str = "red apple";
	
	cout << str.compare(s) << endl;//str > s: 1; str = s: 0; str < s: -1
	cout << str.compare(4, 5, "apple") << endl;//0
	cout << str.compare(4, 5, s, 6, 5) << endl;//0
	
	//str.copy()
	char buffer[20];
	str = "Test string...";
	int length = str.copy(buffer, 6, 5);//"string"
	buffer[length] = '\0';
	cout << buffer << endl;
	
	//str.c_str();
	str = "Please split this sentence into tokens";
	const char* cstr = new char [str.length()+1];
	cstr = str.c_str();
	cout << str.c_str() << endl;
	cout << cstr << endl;
	
	//str.data()
	cout << str.data() << endl;
	char *ccstr = "Please split this sentence into tokens";
	cout << memcmp(ccstr, str.data(), str.length()) << endl;
	
	//str.empty()
	str.clear();
	cout << str.empty() << endl;
	
	//str.erase()
	str = "This is an example sentence";
	str.erase(10, 8);//"This is an sentence"
	str.erase(str.begin()+9);//"This is a sentence"
	str.erase(str.begin()+5, str.end()-9);//"This sentence"
	str.erase(4);//"This"
	cout << str << endl;
	
	//str.find()
	str.clear();
	str = "There are two needles in this haystack with needles.";
	s = "needle";
	int found = str.find(s);
	if (found != string::npos) cout << found << endl;//14
	
	found = str.find("needles are small", found+1, 6);
	if (found != string::npos) cout << found << endl;//44
	
	found = str.find('.');
	if (found != string::npos) cout << found << endl;//51
	
	//str.find_first_not_of()
	str = "look for non-alphabetic characters...";
	found = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");
	if (found != string::npos) cout << found << endl;//12
	found = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz ", found+1);
	if (found != string::npos) cout << found << endl;//34
	
	//str.find_first_of()
	str = "PLease, replace the vowels in this sentence by asterisks.";
	found = str.find_first_of("aeiou");
	
	while (found != string::npos) {
		str[found] = '*';
		found = str.find_first_of("aeiou", found+1);
	}
	cout << str << endl;//PL**s*, r*pl*c* th* v*w*ls *n th*s s*nt*nc* by *st*r*sks.
	
	//str.find_last_not_of()
	str = "Please, erase trailing white-spaces   \n";
	s = " \t\f\v\n\r";
	found = str.find_last_not_of(s);
	
	if (found != string::npos) str.erase(found+1);//"[Please, erase trailing white-spaces]"
	else str.clear();
	
	//str.find_last_of()
	void SplitFilename(string str);
	str = "/usr/bin/man";
	SplitFilename(str);
	str = "c:\\windows\\winhelp.exe";
	SplitFilename(str);
	
	//str.insert()
	str="to be question";
	std::string str2="the ";
	std::string str3="or not to be";
	std::string::iterator it;
	
	// used in the same order as described above:
	str.insert(6,str2);                 // to be (the )question
	str.insert(6,str3,3,4);             // to be (not )the question
	str.insert(10,"that is cool",8);    // to be not (that is )the question
	str.insert(10,"to be ");            // to be not (to be )that is the question
	str.insert(15,1,':');               // to be not to be(:) that is the question
	it = str.insert(str.begin()+5,','); // to be(,) not to be: that is the question
	str.insert (str.end(),3,'.');       // to be, not to be: that is the question(...)
	str.insert (it+2,str3.begin(),str3.begin()+3); // (or )
	
	std::cout << str << '\n';
	
	//operator +=
	str = "a";
	str += "lalala";
	str += str;
	str += 'a';
	cout << str << endl;
	
	//opertor = 
	str.clear();
	s = "lalala";
	str = "wujiarong ";//c_string
	str = str+s;//string
	str = 's';//single character
	
	//poerator []
	cout << str[0] << endl;
	
	//str.replace()
	std::string base="this is a test string.";
	str2="n example";
	str3="sample phrase";
	std::string str4="useful.";
	
	// replace signatures used in the same order as described above:
	
	// Using positions:                 0123456789*123456789*12345
	str=base;           // "this is a test string."
	str.replace(9,5,str2);          // "this is an example string." (1)
	str.replace(19,6,str3,7,6);     // "this is an example phrase." (2)
	str.replace(8,10,"just a");     // "this is just a phrase."     (3)
	str.replace(8,6,"a shorty",7);  // "this is a short phrase."    (4)
	str.replace(22,1,3,'!');        // "this is a short phrase!!!"  (5)
	
	// Using iterators:                                               0123456789*123456789*
	str.replace(str.begin(),str.end()-3,str3);                    // "sample phrase!!!"      (1)
	str.replace(str.begin(),str.begin()+6,"replace");             // "replace phrase!!!"     (3)
	str.replace(str.begin()+8,str.begin()+14,"is coolness",7);    // "replace is cool!!!"    (4)
	str.replace(str.begin()+12,str.end()-4,4,'o');                // "replace is cooool!!!"  (5)
	str.replace(str.begin()+11,str.end(),str4.begin(),str4.end());// "replace is useful."    (6)
	std::cout << str << '\n';
	
	//str.resize()
	str = "I like to code in C";
	str.resize(str.length()+2, '+');//"I like to code in C++"
	str.resize(14); // "I like to code"
	cout << str << endl;
	
	//str.rfind()
	str = "The sixth sick sheik's sixth sheep's sick.";
	std::string key ("sixth");
	
	found = str.rfind(key);
	if (found!=std::string::npos)
	str.replace (found,key.length(),"seventh");
	
	std::cout << str << '\n';

	//str.substr()
	str="We think in generalities, but we live in details.";
	                                       // (quoting Alfred N. Whitehead)
	
	str2 = str.substr (12,12);   // "generalities"
	
	std::size_t pos = str.find("live");      // position of "live" in str
	
	str3 = str.substr (pos);     // get from "live" to the end
	
	std::cout << str2 << ' ' << str3 << '\n';

	system("pause");
}
void SplitFilename(string str) {
	cout << "Splitting: " << str << endl;
	int found = str.find_last_of("/\\");
	cout << " path: " << str.substr(0, found) << endl;
	cout << " file: " << str.substr(found+1) << endl;
}
