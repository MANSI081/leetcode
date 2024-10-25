class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
    //sort the folders lexiographically so parent folderscome before their subfolders
    sort(folder.begin(),folder.end());

    //initialize result vector with the first folder
    vector<string>ans;
    ans.push_back(folder[0]);

    // Iterate through remaining folders starting from index 1
    for(int i=1;i<folder.size();i++){
        // get the last added folder path and add a trailing slash 
        //this helps in comparing if current if current folder is a subfolder
        string lastfolder=ans.back();
        lastfolder.push_back('/');

        //compare current folder with last added folder 
        // compare (0,lastfolder.size(),lastfolder)checks if folder[i] starts with lastfolder
        //if it doesn't start with lastfolder (return !=0), then it's not a subfolder
        if(folder[i].compare(0,lastfolder.size(),lastfolder) !=0){
            //if not a subfolder , add to result
            ans.push_back(folder[i]);
        }
    }
    return ans;
    }
};

