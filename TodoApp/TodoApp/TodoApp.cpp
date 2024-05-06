#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>

using namespace std;

// タスクを表す構造体
struct Task {
    string description;
    time_t deadline;
};

// Todoアプリのクラス
class TodoApp {
private:
    vector<Task> tasks;
    string filename;

public:
    // コンストラクタ
    TodoApp(string filename) : filename(filename) {
        loadTasks(); // タスク読み込み
    }

    // タスクをファイルから読み込む関数
    void loadTasks() {
        ifstream file(filename); // ファイルを開く
        if (file.is_open()) {
            Task task;
            while (getline(file, task.description)) {
                file >> task.deadline;
                tasks.push_back(task);
                file.ignore();
            }
            file.close();
        }
    }

    // タスクをファイルに保存する関数
    void saveTasks() {
        ofstream file(filename); // ファイルを開く（新規作成または上書き）
        if (file.is_open()) {
            for (const auto& task : tasks) {
                file << task.description << endl;
                file << task.deadline << endl;
            }
            file.close();
        }
    }

    // タスクを追加する関数
    void addTask(string description, time_t deadline) {
        Task task{ description, deadline }; // 新しいタスクを作成
        tasks.push_back(task);
        saveTasks();
    }

    // タスクを削除する関数
    void deleteTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            saveTasks();
        }
        else {
            cout << "無効なタスク番号です。" << endl;
        }
    }

    // タスクをリストする関数
    void listTasks() {
        if (tasks.empty()) {
            cout << "タスクはありません。" << endl;
        }
        else {
            for (size_t i = 0; i < tasks.size(); ++i) {
                tm timeinfo;
                localtime_s(&timeinfo, &tasks[i].deadline);
                char buffer[80];
                strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", &timeinfo);
                cout << i + 1 << ". " << tasks[i].description << " (期限: " << buffer << ")" << endl;
            }
        }
    }

    // 期限が近いタスクを通知する関数
    void notifyTasks() {
        cout << "期限が近いタスク:" << endl;
        time_t currentTime;
        time(&currentTime); // 現在時刻を取得
        for (const auto& task : tasks) {
            if (task.deadline > currentTime && task.deadline - currentTime <= 86400) { // 締め切りが24時間以内の場合
                tm timeinfo;
                localtime_s(&timeinfo, &task.deadline); // 締め切り時刻をローカル時刻に変換
                char buffer[80];
                strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", &timeinfo);
                cout << "- " << task.description << " (期限: " << buffer << ")" << endl;
            }
        }
    }

    // メニューを表示する関数
    void displayMenu() {
        cout << "\nTodo App メニュー:\n";
        cout << "1. タスクを追加する\n";
        cout << "2. タスクを削除する\n";
        cout << "3. タスクをリストする\n";
        cout << "4. 期限が近いタスクを通知する\n";
        cout << "5. 終了する\n";
    }

    // アプリを実行する関数
    void run() {
        int choice;
        do {
            displayMenu(); // メニューを表示
            cout << "選択してください: ";
            cin >> choice; // ユーザーの選択を読み込む

            switch (choice) {
            case 1: {
                string description;
                cout << "タスクの説明を入力してください: ";
                cin.ignore();
                getline(cin, description);
                time_t deadline;
                while (true) {
                    cout << "タスクの期限を入力してください (Unix タイムスタンプ): ";
                    if (cin >> deadline) {
                        break;
                    }
                    else {
                        cout << "無効な入力です。有効な Unix タイムスタンプを入力してください。" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                addTask(description, deadline);
                break;
            }
            case 2: {
                int index;
                cout << "削除するタスクの番号を入力してください: ";
                cin >> index;
                deleteTask(index - 1);
                break;
            }
            case 3:
                listTasks();
                break;
            case 4:
                notifyTasks();
                break;
            case 5:
                cout << "終了します..." << endl;
                break;
            default:
                cout << "無効な選択です。もう一度試してください。" << endl;
            }
        } while (choice != 5);
    }
};

int main() {
    TodoApp todoApp("tasks.txt");
    todoApp.run();
    return 0;
}
