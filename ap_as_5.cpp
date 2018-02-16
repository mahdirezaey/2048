#include<string>
#include<vector>
#include<locale>
#include<iostream>
//#include<stdlib.h>

using namespace std;

bool vojood_moteghaier(char ch)
{
    static vector<char> vec_char;

    for(int i=0;i<vec_char.size();i++)
        if(vec_char[i] == ch)
            return 1;
    return 0;
}

int ja_yab (char ch  , vector<vector<int> > &array_marhale ,vector<string> &vec_str )
{
    // enghadr bere ta samt chap =  ch bashe bad inex ye khone badish ro bargar done
    for(int i=array_marhale.size();i>0;i--)
    {
        for(int j=0 ;j<array_marhale[i].size();j--)
            if(vec_str[ array_marhale[i][j] ][0] == 'ch')
                return i+1;

    }

    return array_marhale.size();
}

bool Isalpha(char ch)
{
    char i;
    for( i= 'A' ;i <= 'z' ; i++)
        if(ch == i)
            return 1;
    return 0;
}

int Min(vector<int> &ja_array_marhale)
{
    int min=ja_array_marhale[0];

    for(int i=1;i<ja_array_marhale.size();i++)
        if(min>ja_array_marhale[i])
            min=i;
    return min;
}

void ham_zaman (vector<string> &vec_str)
{
    vector<vector<int> > array_marhale();
/*
    for(int i=0 ;i<vec_str.size();i++)
    {
        array_marhale[i][0]=0;
        array_marhale[i][1]=0;
    }
*/
    vector<string> :: iterator it_vec_str;

    for(it_vec_str = vec_str.begin() +1 ; it_vec_str != vec_str.end() ; it_vec_str++)
    {
        if(vojood_moteghaier(it[0]) == 1)
            array_marhale.push_back(it[0]);
        else
        {
            bool flag_betasavi_residan =0, flag_alpha_baad_tasavi=0;

            vector<int> ja_array_marhale;

            for(int i=0 ;i<vec_str.size();i++)
            {
                if(it_vec_str[i] == "=")
                    flag_betasavi_residan=1;

                if(flag_betasavi_residan==1 && Isalpha( vec_str[i][3]) /*porcesh isalpha*/ && vojood_moteghaier(it_vec_str[i]) ==1 )   // moshkel dare !!
                {
                    ja_array_marhale.push_back(ja_yab(it_vec_str[i] , array_marhale,vec_str ));  //  doroste in ja ??
                    flag_alpha_baad_tasavi =1;
                }

                if(flag_alpha_baad_tasavi == 0)
                    array_marhale[0].push_back();
                else
                {
                    int index= Min(ja_array_marhale);

                    if(array_marhale[index][0] == 0)
                        array_marhale[index][0] = it_vec_str[i] ;
                }

            }

        }

    }

}


int main()
{
    vector<string> vec_str;
    string s;

    //std::vector<std::vector<int> > twoDimVector(3, std::vector<int>(2, 0));

    //string sharp = "";
    //char ch ='abc';
    //cout<<ch;
    //vector<vector<int> > array_marhale(3,vector<int> (2));
    //cout<<twoDimVector.size();

    vec_str.push_back("Oops!");

    //cout<<vec_str.size();

    cin>>s;

    while(s != "#")
    {
        vec_str.push_back(s);
        cin>>s;
    }

    ham_zaman(vec_str);

    //cout<< vec_str[0][0];



    return 0;
}
