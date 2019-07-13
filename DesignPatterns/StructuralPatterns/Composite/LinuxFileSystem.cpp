/*
Output:
/
|--usr
|--|--bin
|--|--|--chrome
|--|--lib
|--|--|--libcbe.so
|--var
|--|--www
|--home
|--|--manoj
|--|--snehal
*/

#include<bits/stdc++.h>
using namespace std;

class IFile{
  public:
    virtual void ls(string space) = 0;
};

class File : public IFile {
    string name;
public:
    File(string name = "No Name")
    {
        this->name = name;
    }
    void ls(string space) override
    {
        cout << space << name << endl;
    }
};

class Directory : public IFile {
    string name;
    vector<IFile*> children;
public:
    Directory(string name) {
        this->name = name;
    }
    void add(IFile *f)
    {
        children.push_back(f);
    }
    void ls(string space) override {
        cout << space <<name << endl;
        space += "|--";
        for(const auto &v : children)
            v->ls(space);
    }
};

int main()
{
    Directory *root = new Directory("/");
    
    Directory *usr = new Directory("usr");
    Directory *var = new Directory("var");
    Directory *home = new Directory("home");
    
    Directory *bin = new Directory("bin");
    bin->add(new File("chrome"));
    
    Directory *lib = new Directory("lib");
    lib->add(new File("libcbe.so"));

    usr->add(bin);
    usr->add(lib);
    
    var->add(new Directory("www"));
    
    home->add(new Directory("manoj"));
    home->add(new Directory("snehal"));
    
    root->add(usr);
    root->add(var);
    root->add(home);
    root->ls("");
}
