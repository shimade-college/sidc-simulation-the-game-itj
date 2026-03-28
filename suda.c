#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



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

    printf("�悤����\n");
    sleep(1);

    printf("���w����w�Ȃ�I�����Ă�������\n");
    printf("1: IT��  2: VD��\n");
    scanf("%d", &s.gakka);

    printf("���O����͂��Ă�������\n");
    scanf("%s", s.name);

    return s;
}


void menuIT(Student s) {
    Status st = {0, 0, 0, 0};

    int gakunen = 1;
    int month = 1;
    int maxmonth = 12;
    int choice;
    char kaishamenu;
    int up_c;
    int up_it;
    int up_linux;

    printf("\n%s ����� IT�Ȑ������n�܂����I\n", s.name);

    while (month <= maxmonth) {
        int month_total=0;
        int weekmonth = 1;
        sleep(1);
        printf("\n====== %d������ ======\n", month);

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



            printf("\n%d������ %d�T��\n", month, weekmonth);

            printf("�X�e�[�^�X�p�l��\n");
            printf("1: C����   +%d\n", up_c);
            printf("2: IT�p�X  +%d\n", up_it);
            printf("3: LINUX   +%d\n", up_linux);
            printf("4: �x��(�X�g���X�l�j -%d\n",down_stress);

            printf("�I��: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    st.cgengo += up_c;
                    printf("C���ꂪ +%d �オ�����I\n", up_c);
                    month_total += up_c;
                    st.stress++;
                    break;
                case 2:
                    st.ipass += up_it;
                    printf("IT�p�X�� +%d �オ�����I\n", up_it);
                    month_total += up_it;
                    st.stress++;
                    break;
                case 3:
                    st.linux += up_linux;
                    printf("LINUX�� +%d �オ�����I\n", up_linux);
                    month_total += up_linux;
                    st.stress++;
                    break;
                case 4:
                    st.stress -= down_stress;
                    printf("���T�͋x�� �X�g���X�l��%d��������!\n",down_stress);
                    break;
                default:
                    printf("�����ȑI���ł�\n");
                    break;
            }
            sleep(1);
            if (weekmonth == 4) {/*���Ɖۑ�C�x���g*/
                printf("\n--- �����ۑ蔭���I ---\n");
                printf("�����̍��v�l20�ȏ�Ȃ�N���A�@�����̐������v: %d\n", month_total);

                if (month_total >= 20) {
                    printf("�ۑ�N���A�I �X�g���X -2\n");
                    st.stress -= 2;
                } else {
                    printf("���v�l��20�ȏ�łȂ����߃_�C�X���[�������s���܂�");
                    int dice = rand() % 2;
                    if (dice == 0) {
                        printf("�ۑ�N���A�I �X�g���X -2\n");
                        st.stress -= 2;
                    }
                    else{
                    printf("�ۑ莸�s�c �X�g���X +3\n");
                    st.stress += 3;
                    }
                }
            }
            weekmonth++;

        }
        if (month==6) {
            printf("\n======資格受験を行います======\n");
            int sikaku = 45;
            int goukaku = 1;
            printf("現在のステータス\n");
            printf("C言語  : %d\n", st.cgengo);
            printf("ITパス : %d\n", st.ipass);
            printf("LINUX  : %d\n", st.linux);
            printf("ストレス　：%d\n", st.stress);
            if (st.cgengo<sikaku) {
                printf("このままのステータスではc言語試験に合格できません。\n");
                printf("ダイスロールして合格しますか？ 5:YES 6:NO\n");
                scanf("%d", &choice);
                if (choice == 5 || choice == 6) {
                    printf("5:YES 6:NO\n");
                    switch (choice) {
                        case 5:
                            goukaku = rand() % 4;
                            if (goukaku==1) {
                                printf("おめでとう！c言語試験に合格しました！\n");
                                printf("ストレス　:%d\n",st.stress);
                            }
                            else
                                printf("c言語試験不合格\n");
                            break;
                        case 6:
                            printf("c言語試験不合格\n");
                            break;
                    }
                }
            }
                if (st. cgengo > sikaku) {
                    printf("おめでとう！c言語試験に合格しました！\n");
                    st.stress -= st.stress;
                    printf("ストレス　:%d\n",st.stress);
                }

                if (st.ipass<sikaku) {
                    printf("このままのステータスではITパスポートに合格できません。\n");
                    printf("ダイスロールして合格しますか？ 5:YES 6:NO\n");
                    scanf("%d", &choice);
                    if (choice == 5 || choice == 6) {
                        printf("5:YES 6:NO\n");
                        switch (choice) {
                            case 5:
                                goukaku = rand() % 4;
                                if (goukaku==1) {
                                    printf("おめでとう！ITパスポートに合格しました！\n");
                                    printf("ストレス　:%d\n",st.stress);
                                }
                                else
                                    printf("ITパスポート不合格\n");
                                break;
                            case 6:
                                printf("ITパスポート不合格\n");
                                break;
                        }
                    }
                }
                if (st.ipass> sikaku) {
                    printf("おめでとう！ITパスポートに合格しました！\n");
                    st.stress -= st.stress;
                    printf("ストレス　:%d\n",st.stress);
                }

                if (st.linux<sikaku) {
                    printf("このままのステータスではlinux試験に合格できません。\n");
                    printf("ダイスロールして合格しますか？ 5:YES 6:NO\n");
                    scanf("%d", &choice);
                    if (choice == 5 || choice == 6){
                        printf("5:YES 6:NO\n");
                        switch (choice) {
                            case 5:
                                goukaku = rand() % 4;
                                if (goukaku==1) {
                                    printf("おめでとう！linux試験に合格しました！\n");
                                    printf("ストレス　:%d\n",st.stress);
                                }
                                else
                                    printf("linux不合格\n");
                                break;
                            case 6:
                                printf("linux不合格\n");
                                break;
                        }
                    }
                }
                if (st.linux > sikaku) {
                    printf("おめでとう！linux試験に合格しました！\n");
                    st.stress -= st.stress;
                    printf("ストレス　:%d\n",st.stress);
                }
            }

        if (weekmonth==4) {
            char kaishamenu;
            printf("�������Ȃ����A�E��̉�ЂɕK�v�ȃX�e�[�^�X���������ꍇY���������Ȃ��ꍇ��yes�������Ă�������");
            scanf("%d", &kaishamenu);
            if (kaishamenu == 'y') {
                printf("CyberLife c����60�ȏ�\n");
                printf("�������dit Linux60�ȏ�\n");
            } else {
                printf("���̌��ֈڍs���܂�");
            }


        }
        if (gakunen == 2 && month == 3) {

        }


        if (gakunen == 1 && month == 11) {/*�i������*/

            int select;
            int select_seisaku = 0;

            printf("\n=== �i������C�x���g ===\n");
            printf("���앪���I�����Ă�������\n");
            printf("1: C����\n");
            printf("2: IT�p�X\n");
            printf("3: LINUX\n");
            printf("�I��: ");
            scanf("%d", &select);

            if (select == 1) {
                select_seisaku = st.cgengo;
                printf("C�����I�����܂���\n");
            } else if (select == 2) {
                select_seisaku = st.ipass;
                printf("IT�p�X��I�����܂���\n");
            } else if (select == 3) {
                select_seisaku = st.linux;
                printf("LINUX��I�����܂���\n");
            } else {
                printf("�����ȑI���ł�\n");
                select_seisaku = 0;
            }

            printf("�I�𕪖�̌��ݒl: %d\n", select_seisaku);

            if (select_seisaku >= 60) {
                printf("�i������ ���i\n");
                printf("�X�g���X�� 5 ��������\n");
                st.stress -= 5;
            } else {
                printf("���v�l��60�ȏ�łȂ����߃_�C�X���[�������s���܂�");
                int dice = rand() % 3;
                if (dice == 0) {
                    printf("�i������ ���i\n");
                    printf("�X�g���X���@5�@��������\n");
                    st.stress -= 2;
                } else {
                printf("�i������ �s���i\n");
                printf("�X�g���X�� 5 �オ����\n");
                st.stress += 5;
                }
            }
        }


        sleep(1);
        printf("\n--- %d������ �I�����X�e�[�^�X ---\n", month);
        printf("C����  : %d\n", st.cgengo);
        printf("IT�p�X : %d\n", st.ipass);
        printf("LINUX  : %d\n", st.linux);
        printf("�X�g���X�@�F%d\n", st.stress);

        if (month == 12) {
            gakunen = 2;
            sleep(1);
            printf("\n========================\n");
            printf("1�N�Ԃ��I�����܂���\n");
            sleep(1);
            printf("2�N���ɐi�����܂����I\n");
            printf("========================\n");

            month = 0;
        }


        month++;
    }

    printf("\n=== %d�����Ԃ̈琬�I���I ===\n", maxmonth);
}

void menuVD(Student s) {
    printf("%s ����A�悤����VD�ȂցI\n", s.name);
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

