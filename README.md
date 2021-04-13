# Отчёт по lab02 

## Сначала были выполнены команды из учебного материала

```sh
export GITHUB_USERNAME=matveybaykalov
export GITHUB_EMAIL=m.baykalov@mail.ru
export GITHUB_TOKEN=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

cd ${GITHUB_USERNAME}/workspace
source scripts/activate

mkdir ~/.config
cat > ~/.config/hub <<EOF
github.com:
- user: ${GITHUB_USERNAME}
  oauth_token: ${GITHUB_TOKEN}
  protocol: https
EOF
git config --global hub.protocol https

mkdir projects/lab02 && cd projects/lab02
git init
git config --global user.name ${GITHUB_USERNAME}
git config --global user.email ${GITHUB_EMAIL}
git config -e --global
git remote add origin https://github.com/${GITHUB_USERNAME}/lab02.git
git pull origin master
touch README.md
git status
git add README.md
git commit -m"added README.md"
git push origin master

touch .gitignore
cat > .gitignore <<EOF
*build*/
*install*/
*.swp
.idea/
EOF

git pull origin master
git log

mkdir sources
mkdir include
mkdir examples
cat > sources/print.cpp <<EOF
#include <print.hpp>

void print(const std::string& text, std::ostream& out)
{
  out << text;
}

void print(const std::string& text, std::ofstream& out)
{
  out << text;
}
EOF

cat > include/print.hpp <<EOF
#include <fstream>
#include <iostream>
#include <string>

void print(const std::string& text, std::ofstream& out);
void print(const std::string& text, std::ostream& out = std::cout);
EOF

cat > examples/example1.cpp <<EOF
#include <print.hpp>

int main(int argc, char** argv)
{
  print("hello");
}
EOF

cat > examples/example2.cpp <<EOF
#include <print.hpp>

#include <fstream>

int main(int argc, char** argv)
{
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
EOF

vim README.md

git status
git add .
git commit -m"added sources"
git push origin master
```

## Выполнение домашнего задания

### Part I

1. Был создан репозиторий task_timp_lab02 на github
2. Была создана локальная папка task_timp_lab02 и проинициализирована
   ```sh
   mkdir task_timp_lab02
   cd task_timp_lab02
   git init
   git remote add origin https://github.com/matveybaykalov/task_timp_lab02.git
    ```
3. ```sh
   touch hello_world.cpp
   vim hellp_world.cpp
    ```
   В файл был помещён текст:
    ```c++
    #include <iostream>
    
    using namespace std;
    
    int main() {
    cout << "Hello, world!" << endl;
    return 0;
    }

    ```
5. ```sh
   git add .
   git commit -m "First commit. Make simple program"
    ```
6. ```sh
   vim hello_world.cpp
   ```
   В файл был помещён текст:
   ```c++
    #include <iostream>
    #include <string>
    
    using namespace std;
    
    int main() {
    string name;
    cin >> name;
    cout << "Hello world from " << name << endl;
    return 0;
    }

    ```
7. Повторно добавлять файл не нужно, так как гит уже "следит" за файлом *hello_world.cpp*
    ```sh
   git commit -m "Change program hello_world.cpp"
    ```
8. ```sh
   git push origin master
   ```
9. ```sh
   git log
   ```

### Part II
1. ```sh
   git branch patch1
   ```
2. ```sh
   git checkout patch1
   vim hello_world.cpp
   ```
  Код был изменён на:
    ```c++
    #include <iostream>
    #include <string>
    
    int main() {
    std::string name;
    std::getline(std::cin, name);
    std::cout << "Hello world from " << name << std::endl;
    return 0;
    }

    ```
3. ```sh
   git add .
   git commit -m "Create new branch and chande code"
   git push origin patch1
   ```
4. Да, ветка доступна
5. Был создан pull-request `patch1 -> master`
6. ```sh
   vim hello_world.cpp
   ```
   Был добавлен комментарийЖ
   ```c++
    std::getline(std::cin, name); //здесь запрашивается имя у пользователя   
   ```
7. ```sh
   git commit -m "Added comments"
   git push origin patch1
   ```
8. Появились изменения в PR
9. выполнил слияние и удалил через гитхаб ветку 
10. ```sh
    git pull
    ```
11. ```sh
    git log
    ```    
12. Для удаления ветки использовал команду:
    ```sh
    git checkout master
    git branch -D patch1 
    ```
### Part III
1. ```sh
   git branch patch2
   git checkout patch2
   ```
2. ```sh
   clang-format --style=Mozilla hello_world.cpp
   ```
3. ```sh
   git commit -m "After clanf-format"
   ```
4. Был создан PR `parch2 -> master`
   В ветке **master** в коде перевел комментарий
5. В PR появились конфликты
6. ```sh
   git pull origin master
   git rebase master
   ```
  В терминале появились конфликты и для их исправления использовал *vim*
  Полсе всех исправления снова выполнил rebase
   ```sh
   git rebase master
   ```
7. ```sh   
   git push -f origin patch2
   ```
8. В PR пропали конфликты
9. Завершил мерж `patch2 -> master`
