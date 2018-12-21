#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <functional>

using namespace std;

string r[21][2];

void rules(){
    r[0][0] = "(S)";
    r[0][1] = "(a)(Q)";
    r[1][0] = "(Q)";
    r[1][1] = "(b)(Q)";
    r[2][0] = "(Q)";
    r[2][1] = "(b+)";

    r[3][0] = "(b+)(#)";
    r[3][1] = "(b*)(#)";
    r[4][0] = "(b)(b*)";
    r[4][1] = "(b*)(c)";
    r[5][0] = "(a)(b*)";
    r[5][1] = "(a*)(a-)";
    r[6][0] = "(a)(a*)";
    r[6][1] = "(a*)(a-)";
    r[7][0] = "(#)(a*)";
    r[7][1] = "(#)(a+)";

    r[8][0] = "(a-)(a)";
    r[8][1] = "(a)(a-)";
    r[9][0] = "(a-)(#)";
    r[9][1] = "(a)(-#)";
    r[10][0] = "(b-)(b)";
    r[10][1] = "(b)(b-)";
    r[11][0] = "(a-)(b)";
    r[11][1] = "(a)(b-)";
    r[12][0] = "(b-)(#)";
    r[12][1] = "(b)(-#)";
    r[13][0] = "(b-)(c)";
    r[13][1] = "(b)(b)";
    r[14][0] = "(a-)(c)";
    r[14][1] = "(a)(b)";
    r[15][0] = "(-#)";
    r[15][1] = "(#)";

    r[16][0] = "(a+)(a)";
    r[16][1] = "(a)(a+)";
    r[17][0] = "(a+)(b)";
    r[17][1] = "(a)(b+)";
    r[18][0] = "(b+)(b)";
    r[18][1] = "(b)(b+)";
    r[19][0] = "(b+)(c)";
    r[19][1] = "(b)(b0)";
    r[20][0] = "(a+)(c)";
    r[20][1] = "(a)(b0)";

    r[21][0] = "(b0)(c)";
    r[21][1] = "(b)(0c)";
    r[22][0] = "(0c)";
    r[22][1] = "(.c)";
    r[23][0] = "(b)(.c)";
    r[23][1] = "(b.)(c)";
    r[24][0] = "(b)(b.)";
    r[24][1] = "(b.)(b)";
    r[25][0] = "(a)(b.)";
    r[25][1] = "(a.)(b)";
    r[26][0] = "(a.)";
    r[26][1] = "(a*)";

    r[27][0] = "(a+)(#)";
    r[27][1] = "(t)(#)";
    r[28][0] = "(a)(t)";
    r[28][1] = "(t)(t)";
}

int main() {
    string s = "(#)(S)(#)";
    vector <pair <int, string> >  tree;

    int n;
    rules();

    freopen("example_derivation_11.txt", "w", stdout);

    cin>>n;

    tree.push_back(make_pair(-1, s));
    s = "(#)(a)(Q)(#)";
    tree.push_back(make_pair(0, s));
    //cout<<s<<endl;

    for(int i = 1; i < n - 1; i++){
        s.replace(6, 0, "(b)");
        tree.push_back(make_pair(1, s));
        //cout<<s<<endl;
    }

    s.replace(n * 3, 3, "(b+)");
    tree.push_back(make_pair(2, s));
    //cout<<s<<endl;

    int e1 = 1, e;
    while(e1){
        e1 = 0;
        e = 1;
        while(e){
            e = 0;
            for(int i = 3; i <= 7; i ++){
                auto index  = s.find(r[i][0]);
                if (index != std::string::npos) {
                    s.replace(index, r[i][0].size(), r[i][1]);
                    e = 1;
                    e1 = 1;
                    tree.push_back(make_pair(i, s));
                    //cout<<s<<endl;
                }
            }
        }
        e = 1;
        while(e){
            e = 0;
            for(int i = 8; i <= 15; i ++){
                auto index  = s.find(r[i][0]);
                if (index != std::string::npos) {
                    s.replace(index, r[i][0].size(), r[i][1]);
                    e = 1;
                    e1 = 1;
                    tree.push_back(make_pair(i, s));
                    //cout<<s<<endl;
                }
            }
        }
        e = 1;
        while(e){
            e = 0;
            for(int i = 16; i <= 20; i ++){
                auto index  = s.find(r[i][0]);
                if (index != std::string::npos) {
                    s.replace(index, r[i][0].size(), r[i][1]);
                    e = 1;
                    e1 = 1;
                    tree.push_back(make_pair(i, s));
                    //cout<<s<<endl;
                }
            }
        }
        e = 1;
        while(e){
            e = 0;
            for(int i = 21; i <= 26; i ++){
                auto index  = s.find(r[i][0]);
                if (index != std::string::npos) {
                    s.replace(index, r[i][0].size(), r[i][1]);
                    e = 1;
                    e1 = 1;
                    tree.push_back(make_pair(i, s));
                    //cout<<s<<endl;
                }
            }
        }
    }
    e = 1;
    e1 = 0;
    while(e){
        e = 0;
        for(int i = 27; i <= 28; i ++){
            auto index  = s.find(r[i][0]);
            if (index != std::string::npos) {
                s.replace(index, r[i][0].size(), r[i][1]);
                e = 1;
                e1 = 1;
                tree.push_back(make_pair(i, s));
                //cout<<s<<endl;
            }
        }
    }
    int m;
    if (e1 == 0) cout << "NOT PRIME\n"; else {
        cout<<"0. "<< tree[0].second<<"\n";
        for(int i = 1; i < tree.size(); i++){
            m = tree[i].first;
            cout<<i<<". " << r[m][0]<<" -> "<<r[m][1] << " : " << tree[i].second<<"\n";
        }
        //cout << s << endl;
    }
    return 0;
}