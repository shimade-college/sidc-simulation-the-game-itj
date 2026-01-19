#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


//test
//test
//test
typedef struct {
    int gakka;
    char name[20];
} Student;

typedef struct {
    int cgengo;
    int linux;
    int ipass;
    int stress;
} Status;
Student start() {
    Student s;

    printf("ようこそ\n");
    sleep(1);

    printf("入学する学科を選択してください\n");
    printf("1: IT科  2: VD科\n");
    scanf("%d", &s.gakka);

    printf("名前を入力してください\n");
    scanf("%s", s.name);

    return s;
}


void menuIT(Student s) {
    Status st = {0, 0, 0, 0};

    int month = 1;
    int maxmonth = 12;
    int choice;

    int up_c;
    int up_it;
    int up_linux;

    printf("\n%s さんの IT科生活が始まった！\n", s.name);

    while (month <= maxmonth) {
        int month_total=0;
        int weekmonth = 1;
        sleep(1);
        printf("\n====== %dか月目 ======\n", month);

        while (weekmonth <= 4) {


            if (st.stress <=4) {
             up_c     = rand() % 5 + 3;
             up_it    = rand() % 5 + 3;
             up_linux = rand() % 5 + 3;
            } else if (st.stress <=6) {
                 up_c     = rand() % 5 + 2;
                 up_it    = rand() % 5 + 2;
                 up_linux = rand() % 5 + 2;
            } else if (st.stress <=8) {
                 up_c     = rand() % 5 + 1;
                 up_it    = rand() % 5 + 1;
                 up_linux = rand() % 5 + 1;
            }
            int down_stress = rand() % 3 + 1;



            printf("\n%dか月目 %d週目\n", month, weekmonth);

            printf("ステータスパネル\n");
            printf("1: C言語   +%d\n", up_c);
            printf("2: ITパス  +%d\n", up_it);
            printf("3: LINUX   +%d\n", up_linux);
            printf("4: 休む(ストレス値） -%d\n",down_stress);

            printf("選択: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    st.cgengo += up_c;
                    printf("C言語が +%d 上がった！\n", up_c);
                    month_total += up_c;
                    st.stress++;
                    break;
                case 2:
                    st.ipass += up_it;
                    printf("ITパスが +%d 上がった！\n", up_it);
                    month_total += up_it;
                    st.stress++;
                    break;
                case 3:
                    st.linux += up_linux;
                    printf("LINUXが +%d 上がった！\n", up_linux);
                    month_total += up_linux;
                    st.stress++;
                    break;
                case 4:
                    st.stress -= down_stress;
                    printf("今週は休んだ ストレス値が%d下がった!\n",down_stress);
                    break;
                default:
                    printf("無効な選択です\n");
                    break;
            }
            sleep(1);
            if (weekmonth == 4) {
                printf("\n--- 月末課題発生！ ---\n");
                printf("今月の合計値20以上ならクリア　今月の成長合計: %d\n", month_total);

                if (month_total >= 20) {
                    printf("課題クリア！ ストレス -2\n");
                    st.stress -= 2;
                } else {
                    printf("課題失敗… ストレス -3\n");
                    st.stress += 3;
                }
            }

            weekmonth++;

        }

        sleep(1);
        printf("\n--- %dか月目 終了時ステータス ---\n", month);
        printf("C言語  : %d\n", st.cgengo);
        printf("ITパス : %d\n", st.ipass);
        printf("LINUX  : %d\n", st.linux);
        printf("ストレス　：%d\n", st.stress);

        month++;
    }

    printf("\n=== %dか月間の育成終了！ ===\n", maxmonth);
}

void menuVD(Student s) {
    printf("%s さん、ようこそVD科へ！\n", s.name);
}

int main() {
    Student student;

    student = start();

    if (student.gakka == 1) {
        menuIT(student);
    }
    else if (student.gakka == 2) {
        menuVD(student);
    }

    return 0;
}

