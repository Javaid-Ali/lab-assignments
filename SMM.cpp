#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <limits>
using namespace std;



void clearScreen()
{
#ifdef _WIN32
    system("cls");
#endif
}

void displayHeader(const string &title)
{
    clearScreen();
    cout << "========================================\n";
    cout << "\t " << title << "\n";
    cout << "========================================\n";
}

void pressEnterToContinue()
{
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// classes
class Post
{
public:
    string username;
    string content;
    time_t timestamp;
    vector<string> hashtags;
    vector<string> likes;

    Post(string user, string post)
    {
        username = user;
        content = post;
        timestamp = chrono::system_clock::to_time_t(chrono::system_clock::now());

        // Extract hashtags
        istringstream iss(post);
        string word;
        while (iss >> word)
        {
            if (word[0] == '#')
            {
                word.erase(remove_if(word.begin(), word.end(),
                                     [](char c)
                                     { return !isalnum(c) && c != '#'; }),
                           word.end());
                hashtags.push_back(word);
            }
        }
    }

    string getTimeString() const
    {
        tm tm_struct;
        localtime_s(&tm_struct, &timestamp);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &tm_struct);
        return string(buffer);
    }
};

class UserNode
{
public:
    string username;
    int age;
    vector<string> friends;
    vector<Post> posts;
    UserNode *next;

    UserNode(string name, int a)
    {
        username = name;
        age = a;
        next = nullptr;
    }

    void addPost(const Post &post)
    {
        posts.push_back(post);
    }

    void displayProfile() const
    {
        cout << "\n=== " << username << "'s Profile ===\n";
        cout << "Age: " << age << "\n";
        cout << "Friends: " << friends.size() << "\n";
        cout << "Posts: " << posts.size() << "\n";

        if (!friends.empty())
        {
            cout << "\nFriends List:\n";
            for (const auto &friendName : friends)
            {
                cout << "- " << friendName << "\n";
            }
        }

        if (!posts.empty())
        {
            cout << "\nRecent Posts:\n";
            int count = 0;
            for (auto it = posts.rbegin(); it != posts.rend() && count < 3; ++it, ++count)
            {
                cout << "[" << it->getTimeString() << "] " << it->content << "\n";
                cout << "Likes: " << it->likes.size() << " | Hashtags: ";
                for (const auto &tag : it->hashtags)
                    cout << tag << " ";
                cout << "\n\n";
            }
        }
    }
};

class UserList
{
private:
    UserNode *head;

public:
    UserList()
    {
        head = nullptr;
    }

    ~UserList()
    {
        UserNode *current = head;
        while (current != nullptr)
        {
            UserNode *next = current->next;
            delete current;
            current = next;
        }
    }

    void addUser(string name, int age)
    {
        if (searchUser(name))
        {
            cout << "User '" << name << "' already exists!\n";
            return;
        }

        UserNode *newNode = new UserNode(name, age);
        if (!head)
            head = newNode;
        else
        {
            UserNode *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "User '" << name << "' added successfully!\n";
    }

    UserNode *searchUser(string name)
    {
        UserNode *temp = head;
        while (temp)
        {
            if (temp->username == name)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void displayAllUsers()
    {
        if (!head)
        {
            cout << "No users in the network.\n";
            return;
        }

        cout << "\n===== All Users =====\n";
        UserNode *temp = head;
        while (temp)
        {
            cout << "Username: " << temp->username
                 << " | Age: " << temp->age
                 << " | Friends: " << temp->friends.size()
                 << " | Posts: " << temp->posts.size() << "\n";
            temp = temp->next;
        }
    }

    bool removeUser(string name)
    {
        if (!head)
        {
            return false;
        }

        if (head->username == name)
        {
            UserNode *toDelete = head;
            head = head->next;
            delete toDelete;
            return true;
        }

        UserNode *temp = head;
        while (temp->next)
        {
            if (temp->next->username == name)
            {
                UserNode *toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void initializeSampleUsers()
    {
        if (head)
        {
            return;
        }

        vector<pair<string, int>> sampleUsers = {
            {"Javaid", 21},
            {"Zainnn", 20},
            {"Subhan", 18},
            {"Sohaib", 19},
            {"Danish", 22}};

        for (const auto &user : sampleUsers)
        {
            addUser(user.first, user.second);
        }

        // Create some sample friendships
        UserNode *Javaid = searchUser("Javaid");
        UserNode *Zainnn = searchUser("Zainnn");
        UserNode *Subhan = searchUser("Subhan");
        UserNode *Sohaib = searchUser("Sohaib");
        UserNode *Danish = searchUser("Danish");

        if (Javaid && Zainnn)
        {
            Javaid->friends.push_back("Zainnn");
            Zainnn->friends.push_back("Javaid");
        }
        if (Zainnn && Subhan)
        {
            Zainnn->friends.push_back("Subhan");
            Subhan->friends.push_back("Zainnn");
        }
        if (Sohaib && Javaid)
        {
            Sohaib->friends.push_back("Javaid");
            Javaid->friends.push_back("Sohaib");
        }
        if (Danish && Subhan)
        {
            Danish->friends.push_back("Subhan");
            Subhan->friends.push_back("Danish");
        }

        cout << "Sample users added successfully!\n";
    }
};

class FriendRequest
{
public:
    string fromUser;
    string toUser;
    time_t timestamp;
    bool pending;

    FriendRequest(string from, string to)
    {
        fromUser = from;
        toUser = to;
        pending = true;

        timestamp = chrono::system_clock::to_time_t(chrono::system_clock::now());
    }

    string getTimeString() const
    {
        tm tm_struct;
        localtime_s(&tm_struct, &timestamp);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &tm_struct);
        return string(buffer);
    }
};

class HashtagNode
{
public:
    string tag;
    int count;
    HashtagNode *left, *right;

    HashtagNode(string t)
    {
        tag = t;
        count = 1;
        left = nullptr;
        right = nullptr;
    }
};

class HashtagBST
{
private:
    HashtagNode *root;

    void inorderTraversal(HashtagNode *node, vector<pair<string, int>> &tags)
    {
        if (!node)
        {
            return;
        }
        inorderTraversal(node->left, tags);
        tags.emplace_back(node->tag, node->count);
        inorderTraversal(node->right, tags);
    }

    HashtagNode *insert(HashtagNode *node, string tag)
    {
        if (!node)
            return new HashtagNode(tag);

        if (tag == node->tag)
        {
            node->count++;
        }
        else if (tag < node->tag)
        {
            node->left = insert(node->left, tag);
        }
        else
        {
            node->right = insert(node->right, tag);
        }
        return node;
    }

public:
    HashtagBST()
    {
        root = nullptr;
    }

    void insertHashtag(string tag)
    {
        root = insert(root, tag);
    }

    void displayTrending()
    {
        vector<pair<string, int>> tags;
        inorderTraversal(root, tags);

        sort(tags.begin(), tags.end(),
             [](const pair<string, int> &a, const pair<string, int> &b)
             {
                 return a.second > b.second;
             });

        cout << "\n===== Trending Hashtags =====\n";
        if (tags.empty())
        {
            cout << "No hashtags yet!\n";
            return;
        }

        for (int i = 0; i < min(10, (int)tags.size()); i++)
        {
            cout << i + 1 << ". #" << tags[i].first << " (" << tags[i].second << " posts)\n";
        }
    }
};

// global data structure
stack<Post> userPosts;
queue<FriendRequest> friendRequests;
unordered_map<string, vector<string>> friendshipGraph;
HashtagBST hashtags;

// functions
void addPost(UserList &users)
{
    string user, post;
    cout << "Enter your username: ";
    cin >> user;

    UserNode *userNode = users.searchUser(user);
    if (!userNode)
    {
        cout << "User not found!\n";
        pressEnterToContinue();
        return;
    }

    cout << "Enter your post (include #hashtags if desired):\n";
    cin.ignore();
    getline(cin, post);

    Post newPost(user, post);
    userPosts.push(newPost);
    userNode->addPost(newPost);

    // Extract and add hashtags to BST
    for (const auto &tag : newPost.hashtags)
    {
        hashtags.insertHashtag(tag.substr(1)); // Remove # for storage
    }

    cout << "\nPost added successfully at " << newPost.getTimeString() << "!\n";
    pressEnterToContinue();
}

void displayRecentPosts()
{
    if (userPosts.empty())
    {
        cout << "No posts available.\n";
        pressEnterToContinue();
        return;
    }

    cout << "\n===== Recent Posts =====\n";
    stack<Post> temp = userPosts;
    int count = 0;
    while (!temp.empty() && count < 5)
    {
        Post post = temp.top();
        cout << "[" << post.getTimeString() << "] " << post.username << ":\n";
        cout << post.content << "\n";
        cout << "Likes: " << post.likes.size() << " | Hashtags: ";
        for (const auto &tag : post.hashtags)
            cout << tag << " ";
        cout << "\n----------------------------------------\n";
        temp.pop();
        count++;
    }
    pressEnterToContinue();
}

void likePost()
{
    if (userPosts.empty())
    {
        cout << "No posts available to like.\n";
        pressEnterToContinue();
        return;
    }

    string user;
    cout << "Current top post: \n\"" << userPosts.top().content << "\"\n";
    cout << "Enter your username to like this post: ";
    cin >> user;

    Post &topPost = const_cast<Post &>(userPosts.top());
    if (find(topPost.likes.begin(), topPost.likes.end(), user) != topPost.likes.end())
    {
        cout << "You've already liked this post!\n";
    }
    else
    {
        topPost.likes.push_back(user);
        cout << "Post liked successfully by " << user << "!\n";
    }
    pressEnterToContinue();
}

void sendFriendRequest(UserList &users)
{
    string fromUser, toUser;
    cout << "Enter your username: ";
    cin >> fromUser;

    if (!users.searchUser(fromUser))
    {
        cout << "User not found!\n";
        pressEnterToContinue();
        return;
    }

    cout << "Enter username you want to friend: ";
    cin >> toUser;

    if (fromUser == toUser)
    {
        cout << "You can't send a friend request to yourself!\n";
        pressEnterToContinue();
        return;
    }

    if (!users.searchUser(toUser))
    {
        cout << "User not found!\n";
        pressEnterToContinue();
        return;
    }

    // Check if already friends
    UserNode *fromNode = users.searchUser(fromUser);
    if (find(fromNode->friends.begin(), fromNode->friends.end(), toUser) != fromNode->friends.end())
    {
        cout << "You're already friends with " << toUser << "!\n";
        pressEnterToContinue();
        return;
    }

    friendRequests.push(FriendRequest(fromUser, toUser));
    cout << "\nFriend request sent successfully at " << friendRequests.back().getTimeString() << "!\n";
    pressEnterToContinue();
}

void processFriendRequests(UserList &users)
{
    if (friendRequests.empty())
    {
        cout << "No pending friend requests.\n";
        pressEnterToContinue();
        return;
    }

    cout << "\n===== Pending Friend Requests =====\n";
    while (!friendRequests.empty())
    {
        FriendRequest req = friendRequests.front();
        cout << "Request from " << req.fromUser << " to " << req.toUser
             << " (sent at " << req.getTimeString() << ")\n";

        cout << "1. Accept\n2. Reject\n3. Skip (keep pending)\n4. Cancel\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            UserNode *fromUser = users.searchUser(req.fromUser);
            UserNode *toUser = users.searchUser(req.toUser);

            if (fromUser && toUser)
            {
                fromUser->friends.push_back(req.toUser);
                toUser->friends.push_back(req.fromUser);
                cout << "\nFriendship established between " << req.fromUser << " and " << req.toUser << "!\n";
            }
        }
        else if (choice == 2)
        {
            cout << "\nRequest rejected.\n";
        }
        else if (choice == 3)
        {
            cout << "\nRequest skipped (will remain in queue).\n";
            break; // Don't remove from queue if skipped
        }
        else if (choice == 4)
        {
            cout << "\nProcessing cancelled.\n";
            break;
        }
        else
        {
            cout << "\nInvalid choice. Please try again.\n";
            continue;
        }

        if (choice != 3 && choice != 4)
        {
            friendRequests.pop();
        }
    }
    pressEnterToContinue();
}

vector<string> suggestFriends(string username, UserList &users)
{
    unordered_map<string, bool> visited;
    unordered_map<string, int> friendCount;
    vector<string> suggestions;

    UserNode *user = users.searchUser(username);
    if (!user){
        return suggestions;
    }

    visited[username] = true;
    for (string friendUser : user->friends)
    {
        visited[friendUser] = true;
    }

    for (string friendUser : user->friends)
    {
        UserNode *friendNode = users.searchUser(friendUser);
        if (friendNode)
        {
            for (string friendOfFriend : friendNode->friends)
            {
                if (!visited[friendOfFriend] && friendOfFriend != username)
                {
                    friendCount[friendOfFriend]++;
                }
            }
        }
    }

    // Sort by mutual friend count
    vector<pair<string, int>> sortedSuggestions(friendCount.begin(), friendCount.end());
    sort(sortedSuggestions.begin(), sortedSuggestions.end(),
         [](const pair<string, int> &a, const pair<string, int> &b)
         {
             return a.second > b.second;
         });

    // Extract top suggestions
    for (int i = 0; i < min(5, (int)sortedSuggestions.size()); i++)
    {
        suggestions.push_back(sortedSuggestions[i].first);
    }

    return suggestions;
}

void viewFriendSuggestions(UserList &users)
{
    string user;
    cout << "Enter your username: ";
    cin >> user;

    vector<string> suggestions = suggestFriends(user, users);
    if (suggestions.empty())
    {
        cout << "\nNo friend suggestions available right now.\n";
    }
    else
    {
        cout << "\n===== Friend Suggestions for " << user << " =====\n";
        cout << "(Based on mutual connections)\n\n";
        // we can also use size_t for this
        for (int i = 0; i < static_cast<int>(suggestions.size()); i++)
        {
            cout << i + 1 << ". " << suggestions[i] << "\n";
        }
    }
    pressEnterToContinue();
}

void printNetworkHelper(string user, unordered_map<string, bool> &visited, UserList &users, int depth)
{
    if (depth > 3)
    {
        return;
    }

    UserNode *userNode = users.searchUser(user);
    if (!userNode)
    {
        return;
    }

    visited[user] = true;

    for (int i = 0; i < depth; i++)
        cout << "  ";
    cout << user << " (friends: " << userNode->friends.size() << ")\n";

    for (string friendUser : userNode->friends)
    {
        if (!visited[friendUser])
        {
            printNetworkHelper(friendUser, visited, users, depth + 1);
        }
    }
}

void printNetwork(UserList &users)
{
    string user;
    cout << "Enter username to start from: ";
    cin >> user;

    unordered_map<string, bool> visited;
    cout << "\n===== Social Network =====\n";

    UserNode *userNode = users.searchUser(user);
    if (!userNode)
    {
        cout << "User not found!\n";
        pressEnterToContinue();
        return;
    };

    printNetworkHelper(user, visited, users, 0);
    pressEnterToContinue();
}

void viewUserProfile(UserList &users)
{
    string username;
    cout << "Enter username: ";
    cin >> username;

    UserNode *user = users.searchUser(username);
    if (!user)
    {
        cout << "User not found!\n";
        pressEnterToContinue();
        return;
    }

    user->displayProfile();
    pressEnterToContinue();
}

// Main Menu
void mainMenu(UserList &users)
{
    while (true)
    {
        displayHeader("SocialMesh Network");
        cout << "1.  Add New User\n";
        cout << "2.  View All Users\n";
        cout << "3.  View User Profile\n";
        cout << "4.  Create Post\n";
        cout << "5.  View Recent Posts\n";
        cout << "6.  Like a Post\n";
        cout << "7.  Send Friend Request\n";
        cout << "8.  Process Friend Requests\n";
        cout << "9.  View Friend Suggestions\n";
        cout << "10. View Trending Hashtags\n";
        cout << "11. View Network\n";
        cout << "12. Initialize Sample Users\n";
        cout << "13. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice (1-13): ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            displayHeader("Add New User");
            string name;
            int age;
            cout << "Enter username: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            users.addUser(name, age);
            pressEnterToContinue();
            break;
        }
        case 2:
        {
            displayHeader("All Users");
            users.displayAllUsers();
            pressEnterToContinue();
            break;
        }
        case 3:
        {
            displayHeader("User Profile");
            viewUserProfile(users);
            break;
        }
        case 4:
        {
            displayHeader("Create Post");
            addPost(users);
            break;
        }
        case 5:
        {
            displayHeader("Recent Posts");
            displayRecentPosts();
            break;
        }
        case 6:
        {
            displayHeader("Like a Post");
            likePost();
            break;
        }
        case 7:
        {
            displayHeader("Send Friend Request");
            sendFriendRequest(users);
            break;
        }
        case 8:
        {
            displayHeader("Process Friend Requests");
            processFriendRequests(users);
            break;
        }
        case 9:
        {
            displayHeader("Friend Suggestions");
            viewFriendSuggestions(users);
            break;
        }
        case 10:
        {
            displayHeader("Trending Hashtags");
            hashtags.displayTrending();
            pressEnterToContinue();
            break;
        }
        case 11:
        {
            displayHeader("View Network");
            printNetwork(users);
            break;
        }
        case 12:
        {
            displayHeader("Initialize Sample Users");
            users.initializeSampleUsers();
            pressEnterToContinue();
            break;
        }
        case 13:
        {
            cout << "\nThank you for using the Social Network Simulator!\n";
            return;
        }
        default:
        {
            cout << "\nInvalid choice! Please try again.\n";
            pressEnterToContinue();
            break;
        }
        }
    }
}

int main()
{
    UserList users;

    // Welcome screen
    displayHeader("Welcome to SocialMesh Network");
    cout << "This program SocialMesh Network with users,\n";
    cout << "posts, friendships, and hashtags.\n\n";
    cout << "Would you like to start with sample users? (y/n): ";

    char choice;
    cin >> choice;
    if (tolower(choice) == 'y')
    {
        users.initializeSampleUsers();
    }

    mainMenu(users);
    return 0;
}