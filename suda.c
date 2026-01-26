void Stetus(){

            if (month==10&&weekmonth==5) {
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
                if (st. cgengo > sikaku) {
                    st.stress -= st.stress;
                    printf("おめでとう！c言語試験に合格しました！\n");
                    printf("ストレス　:%d\n",st.stress);
                }

                if (st.ipass<sikaku) {
                    printf("このままのステータスではITパスポートに合格できません。\n");
                    printf("ダイスロールして合格しますか？ 5:YES 6:NO\n");
                    scanf("%d", &choice);
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
                if (st.ipass> sikaku) {
                    st.stress -= st.stress;
                    printf("おめでとう！ITパスポートに合格しました！\n");
                    printf("ストレス　:%d\n",st.stress);
                }

                if (st.linux<sikaku) {
                    printf("このままのステータスではlinux試験に合格できません。\n");
                    printf("ダイスロールして合格しますか？ 5:YES 6:NO\n");
                    scanf("%d", &choice);
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
                if (st.linux > sikaku) {
                    st.stress -= st.stress;
                    printf("おめでとう！linux試験に合格しました！\n");
                    printf("ストレス　:%d\n",st.stress);
                }
        }
}