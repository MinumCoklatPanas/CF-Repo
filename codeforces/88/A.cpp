#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

vector<string> chords = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H","C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};

int dist(string a,string b)
{
    int posA = -1;
    for (int i = 0 ; i < chords.size() ; i++) if (chords[i] == a)
    {
        posA = i;
        break;
    }
    assert(posA != -1);
    int posB = -1;
    for (int j = posA ; j < chords.size() ; j++) if (chords[j] == b)
    {
        posB = j;
        break;
    }
    assert(posB != -1);
    return posB - posA;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cout << chords.size() << endl;
    vector< string > tab(3);
    cin >> tab[0] >> tab[1] >> tab[2];
    sort(tab.begin(),tab.end());
    do {
        string a = tab[0];
        string b = tab[1];
        string c = tab[2];
        // cout << a << " " << b << " " << c << endl;
        int dist1 = dist(a,b);
    // cout << dist1 << endl;
        int dist2 = dist(b,c);
        if (dist1 == 4 && dist2 == 3)
        {
            cout << "major\n";
            return 0;
        }
        else
        if (dist1 == 3 && dist2 == 4)
        {
            cout << "minor\n";
            return 0;
        }
    } while (next_permutation(tab.begin(),tab.end()));
    cout << "strange\n";
    return 0;
}
