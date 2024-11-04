#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Entry {
private:
    string date;
    string content;
    vector<string> Tags;
public:
    void setDate(string _date)
    {
        date = _date ;
    }
    string getDate()
    {
        return this->date;
    }

    void setContent(string _content)
    {
        content = _content;
    }
    string getContent()
    {
        return this->content;
    }
    string setTags(vector<string>_tags)
    {
        for(auto &_tag: _tags)
        {
            Tags.push_back(_tag);
        }
    }
    bool hasTag(string tag)
    {
        for(auto _tag : Tags)
        {
            if(_tag == tag) return true;
        }
        return false;
    }
    void DisplayEntry()
    {
        cout << "Date: " << date << '\n' ;
        cout << content <<'\n' ;
        for(auto tag : Tags)
        {
            cout << tag << ' ';
        }
        cout << '\n' ;
    }
};
class Diary{
private:
    vector<Entry> Entries ;
public:
    // Function to Create a new entry
    void CreateEntry(string date, string content, vector<string>tags)
    {
        Entry newEntry;
        newEntry.setDate(date);
        newEntry.setTags(tags);
        newEntry.setContent(content);
        Entries.push_back(newEntry);
    }
    //function to display all entries
    void DisplayAllEntries()
    {
        if(Entries.empty())
        {
            cout << "No Entries Found!\n" ;
        }
        else {
                int counter = 1 ;
            for(auto &entry: Entries)
            { cout << "Diary " << counter++ << ": \n" ;
                entry.DisplayEntry();
            }
        }
    }
    // find entry by date
    void  FindEntryByDate(string date)
    {

        bool found = false ;
        for(auto &entry: Entries)
        {
            if(entry.getDate() == date )
            {
                entry.DisplayEntry();
                found = true;
            }
        }
        if(!found) cout << "No Entry found for the date : " << date << '\n' ;
    }
    //edit entry by date
    void EditEntry(string date, string newContent)
    {
        for(auto &entry: Entries)
        {
            if(entry.getDate() == date)
            {
                entry.setContent(newContent) ;
                cout << "Entry Updated.";
                return ;
            }
            cout << "No Entry Found For The Date: " << date <<'\n';

        }
    }
    // delete entry by date
    void DeleteEntry(string date)
    {
        for(auto entry= Entries.begin();entry!=Entries.end();entry++)
        {
            if(entry->getDate() == date)
            {
                Entries.erase(entry);
                return;
            }
        }
         cout << "No Entry Found For The Date : " << date << '\n' ;

    }
    // search entries by tags
    void SearchEntriesByTag(string tag)
    {
        bool found = false ;
        for(auto &entry : Entries)
        {
            if(entry.hasTag(tag)== true)
            {
                entry.DisplayEntry();
                found = true;
            }
        }
        if(!found) cout << "no entries found with tag : " << tag << '\n';
    }
};
void ShowMenu()
{
    cout   << "1. Add Entry\n"
              << "2. View All Entries\n"
              << "3. Find Entry by Date\n"
              << "4. Edit Entry by Date\n"
              << "5. Delete Entry by Date\n"
              << "6. Search Entries by Tag\n"
              << "7. Exit\n";
}
int main()
{
    Diary diary ;
    int option ;
    string date, content, tag;
    while(true){
    ShowMenu();
    cout << "choose an option: \n";
    cin >> option ;
    cin.ignore();
    if(option == 1)
    {
        cout << "Enter Diary Date (DD-MM-YYYY) : \n" ;
        cin >> date;
        cin.ignore();
        cout << "Enter Diary Content: \n";
        getline(cin, content);
        cout << "Enter tags (tag-tag): \n";
        cin >> tag ;
        vector<string>tags;
        string temp="";
        for(int i=0;i<tag.size();i++)
        {
        if(tag[i] == '-')
        {
            tags.push_back(temp);
            temp="";
            continue ;
        }
        temp+=tag[i];
        }
        if(temp!="");
        tags.push_back(temp) ;
        diary.CreateEntry(date,content,tags) ;
        cout << "Entry Added.\n";
    }
    else if(option == 2)
    {
       diary.DisplayAllEntries();
    }
    else if(option == 3)
    {
      cout << "Enter Search Date (DD-MM-YYYY): \n" ;
      cin >> date;
      diary.FindEntryByDate(date) ;
    }
    else if(option == 4)
    {
      cout << "Enter Search Date(DD-MM-YYYY): \n" ;
      cin >> date;
      cout << "Enter New Content: \n" ;
      cin >> content ;
      diary.EditEntry(date, content) ;
      cout << "Edited Entry Successfully.\n";
    }
    else if(option == 5)
    {
      cout << "Enter Date (DD-MM-YYYY): \n" ;
      cin >> date;
      diary.DeleteEntry(date) ;
      cout << "Deleted Entry Successfully.\n" ;
    }
   else  if(option == 6)
    {
     cout << "Enter Tag: \n" ;
     cin >> tag ;
     diary.SearchEntriesByTag(tag) ;
    }
    else if(option == 7)
    {
        "Exiting the Personal Diary App, Hope To See you Again!\n" ;
       return 0 ;
    }
    else {
        cout << "invalid option!\n" ;
    }
}
    return 0;
}
