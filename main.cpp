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

typedef enum {
     MAYA = 1,
     Cyberlife,
     dit,
     jaian,
     Firedragons,


} company;

Student start() {
    Student s;

    printf("ようこそ\n");
    sleep(1);

    printf("入学する学科を選択してください\n");
    printf("1: IT科  2: VD科\n");
    scanf("%d", &s.gakka);

    printf("名前を入力してください\n");
    scanf("%19s", s.name);

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
    int naitei_part1=0;
    int naitei_part2=0;

    printf("\n%s さんの IT科生活が始まった！\n", s.name);
    printf("プレイヤーは毎月の行動を選択し、スキルを伸ばしながらストレスを管理し、最終的にどの会社に就職できるかが決まります。");
    printf("このゲームは キーボードのみで操作します。画面に表示される選択肢の番号を入力し、Enterキーを押すことで行動を決定してください。");

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
                    if (st.stress < 0) st.stress = 0;
                    if (st.stress > 10) st.stress = 10;
            }
            sleep(1);
            if (weekmonth==4) {
                char kaishamenu;
                printf("もしあなたが就職先の会社に必要なステータスを見たい場合Yを見たくない場合はnを押してください\n");
                scanf(" %c", &kaishamenu);
                if (kaishamenu == 'y'||kaishamenu == 'Y') {
                    printf("CyberLife c言語60以上\n");
                    printf("株式会社dit Linux60以上\n");
                } else {
                    printf("月末課題へ移行します");
                }
            }

            if (weekmonth == 4) {/*授業課題イベント*/
                printf("\n=== 月末課題発生！ ===\n");
                printf("今月の合計値20以上ならクリア　今月の成長合計: %d\n", month_total);

                if (month_total >= 20) {
                    printf("課題クリア！ ストレス -2\n");
                    st.stress -= 2;
                } else {
                    printf("合計値が20以上でないためダイスロールを実行します");
                    int dice = rand() % 2;
                    if (dice == 0) {
                        printf("課題クリア！ ストレス -2\n");
                        st.stress -= 2;
                    }
                    else{
                    printf("課題失敗… ストレス +3\n");
                    st.stress += 3;
                    }
                    if (st.stress < 0) st.stress = 0;
                    if (st.stress > 10) st.stress = 10;
                }
            }
            weekmonth++;

        }
        if (gakunen == 1 && month==6) {
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
                            } else {
                                printf("c言語試験不合格\n");
                                st.stress += 2;
                                break;
                            }
                        case 6:
                            printf("c言語試験不合格\n");
                            st.stress += 2;
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
                                    } else {
                                        printf("ITパスポート不合格\n");
                                        st.stress += 2;
                                        break;
                                    }
                                case 6:
                                    printf("ITパスポート不合格\n");
                                    st.stress += 2;
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
                                else {
                                    printf("linux不合格\n");
                                    st.stress += 2;
                                    break;
                                }
                            case 6:
                                printf("linux不合格\n");
                                st.stress += 2;
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



        if (gakunen == 2 && month == 3) {/*就職活動*/
            int kaisha;
            int kaissha_select = 0;
            int kaisha_point = 0;
            int mensetu_hentou =0;
            printf("\n=== 就職活動 ===\n");
            printf("就職活動が始まりました。就職したい会社を選択し面接を行います。面接を通して5ポイント獲得出来たら就職できます。");
            printf("就職したい会社を選択してください");
            printf("1: MAYA");
            printf("2: Cyberlife");
            printf("3: 株式会社dit");
            printf("4: Firedragons");
            printf("5: 橋本製作所");
            printf("6: jaian");
            scanf("%d", &kaisha);
            if (kaisha == 2) {
                kaissha_select = st.cgengo;
                printf("Cyberlifeを選択しました");
                sleep(1);
                printf("いよいよ面接が始まる。私は過去何度か経験しているが、久しぶりと言うこともありかなり緊張していた。というより久しぶりじゃなくても普通に緊張する。何故なら、面接とはその人がどれだけその会社に適応でき、その会社にどれだけ利益をもたらしてくれるかを審査する場所であり、会社にとって採用するまでの最後の砦だと思っているからだ。会社側からしたら下手な人を採用はしたくないだろう。だから向こうも真剣にこちらを見てくる。そう考えると、緊張しない方がおかしい。一人、また一人と面接室に向かっていく。その度に私の心臓は鼓動を大きく、速くしていく。寿命が縮んでいく気すらする。こんなもんをこれからもしていかないといけない可能性があると考えると、生きていくのが少し憂鬱になる。いよいよ私の番が来る。私はさらっと身だしなみの最終確認をし、待機室から出た。一連の動作をし終わり、椅子に座り、面接官と目を合わせる。いよいよ始めの質問が来る。");
                if (kaissha_select <= 60) {
                    kaisha_point += 2;
                } else {
                    kaisha_point -= 0;
                }
                for (int i = 0; i < 3; i++) {
                    if (i==0) {
                        printf(
"面接\n"
"\n"
"「それでは、面接を始めていきます。」\n"
"\n"
"「まず、あなたの名前と特技、そして学生時代に頑張ってきたことがあれば教えてください。」\n"
"\n"
"??まぁ、名前はちゃんと言えばいい。そこは正直どうでもいい。\n"
"問題は『特技』と『学生時代に頑張ったこと』だ。\n"
"急にそう言われると、意外と難しい。\n"
"自分では当たり前だと思ってやってきたことが、\n"
"果たして“特技”や“頑張ったこと”として通用するのか。\n"
"どう答えるべきか、頭の中で必死に言葉を探していた。\n"
);

                        printf("1.特技:引っ越し　頑張った事:金を稼ぐこと \n");
                        printf("2.特技:理解力　頑張った事:C言語 \n");
                        printf("3.特技:ツッコミ　頑張った事:ゲーム制作 \n");
                        scanf("%d", &mensetu_hentou);
                        if (mensetu_hentou == 1) {
                            printf(
"1.「名前は%s、特技は引っ越し作業を無駄なく速くできることです。\n"
"学生時代に頑張ったことは、金を稼ぐことです。」\n"
"\n"
"私は自信満々にそう言い放った。\n"
"しかし、そんな私とは裏腹に、面接官たちの顔には戸惑いの色が浮かんでいた。\n"
"\n"
"「えー……詳しく教えてください。」\n"
"\n"
"困惑しながら、面接官の一人がそう尋ねてきた。\n"
"\n"
"私は「はい」と短く返事をし、話し始めた。\n"
"\n"
"「私は一時期、引っ越し作業のアルバイトをしておりまして、\n"
"その際に荷物を運ぶのが他の人より上手かったため、それを特技としています。\n"
"また、金を稼ぐために複数のアルバイトを掛け持ちし、\n"
"さまざまな経験を積んできました。\n"
"それが私の学生生活の中で最も印象に残っているため、\n"
"学生時代に頑張ったこととして挙げさせていただきました。\n"
"ですので、人一倍の体力と、多様な経験には自信があります。」\n"
"\n"
"最初は困惑していた面接官たちも、\n"
"その返答を聞いた後、納得したような表情を浮かべてくれた。\n",
s.name);
                            kaisha_point -= 1;
                        } else if (mensetu_hentou == 2) {
                            printf(
"2:「名前は%s、特技は物事をすぐに理解できることです。\n"
"学生時代にはC言語を中心にプログラミング言語の使い方を覚え、\n"
"実際に使いこなせるようにすることを頑張りました。」\n"
"\n"
"それを聞いた途端、面接官の一人が面白そうに聞いてきた。\n"
"\n"
"「C言語はどれくらい使いこなせるようになりましたか？」\n"
"\n"
"私は少し考えた後、こう答えた。\n"
"\n"
"「ポインタについてある程度理解しており、\n"
"ポインタを使った簡単なプログラムなら書ける程度には使いこなせます。」\n"
"\n"
"すると、面接官たちはうんうんと頷いてくれた。\n"
"明らかに好印象だ。やった。\n",
s.name);
                            kaisha_point += 1;
                        } else if (mensetu_hentou == 3) {
                            printf(
"「名前は%s、特技はツッコミです。\n"
"学生時代に頑張ったことは、Unityエンジンでゲームを作ることです。」\n"
"\n"
"私が話している途中、面接官の表情が一瞬だけ不思議そうに変わった気がしたが、\n"
"どうやらそれなりに納得はしてくれたようだった。\n"
"\n"
"「Unityエンジンで作ったゲームは、公開していますか？」\n"
"\n"
"面接官の一人が、興味を示した様子でそう尋ねてきた。\n"
"私はすかさず答える。\n"
"\n"
"「人に見せられるレベルのものは公開しています。\n"
"ですが、大半は致命的なバグがまだ修正できておらず、\n"
"人に見せられるレベルではないため、公開していません。」\n"
"\n"
"それを聞くと、その質問をした面接官は、\n"
"『まぁ、無理もないか』というような表情を浮かべていた。\n",
s.name
);


                            kaisha_point += 0;
                        } else {
                            printf("無効な選択脱皮");
                            kaisha_point += 0;
                        }

                    } else if (i==1) {
                        printf("「では、この会社に入社したらしたいことなどはありますか。」\n"
"中々難しい質問が来た。どうしようか。\n");
                        printf("1.成り上がりたい");
                        printf("2.プログラム組みたい");
                        printf("3.まだ決まってない");


                        scanf("%d", &mensetu_hentou);
                        if (mensetu_hentou == 1) {
                            printf(
"「私が御社でしたいことは、出世することです。」\n"
"\n"
"私は高々とそう宣言した。\n"
"\n"
"面接官の一人が、少し間を置いて私に問いかけてきた。\n"
"\n"
"「具体的な出世の計画はありますか。」\n"
"\n"
"??すごい質問だ。\n"
"いや、確かに『入社したらしたいこと』で\n"
"『出世したい』と答える人間は、そう多くないだろう。\n"
"だが、その上を行くような質問を投げてくるとは思っていなかった。\n"
"\n"
"私は少し考えた後、こう答えた。\n"
"\n"
"「十年で、社長まで上りつめたいと考えております。」\n"
"\n"
"その回答を聞いた面接官は、\n"
"「おぉ、そうか」と小さく呟いた。\n"
);
                            kaisha_point -= 1;
                        } else if (mensetu_hentou == 2) {
                            printf(
"「私は人よりもプログラムを組めると思っているので、\n"
"その強みをここで活かしたいです。」\n"
"\n"
"私の回答に、面接官の一人が\n"
"聞かれて当然と言わんばかりの質問をしてきた。\n"
"\n"
"「どのようにしたら、その強みを活かせると思いますか。」\n"
"\n"
"私は少し考えた後、こう答えた。\n"
"\n"
"「機械制御を中心に仕事をしていけば、\n"
"その強みを活かせると思います。」\n"
"\n"
"自分で言っていて、\n"
"??まぁ、当たり前だよな。\n"
"そんな感想が頭に浮かんだ。\n"
);

                            kaisha_point += 2;
                        } else if (mensetu_hentou == 3) {
                            printf(
"「具体的なことはまだ決まっておりませんが、\n"
"とりあえず今は、しっかりと働きたいです。」\n"
"\n"
"このあたりは障りのない回答だ。\n"
"何か突っ込まれるかと身構えていたが、面接官は\n"
"「そうですか。」と一言返しただけで、その話題を流した。\n"
"\n"
"??えぇ……。\n"
"もう少し変わった回答をしておけば良かったかな。\n"
"例えば、「出世したい」とか。\n"
"\n"
"考えても仕方がない。\n"
"気持ちを切り替え、次の質問に集中することにした。\n"
"\n"
"????????????????????????????\n"
"\n"
"「生まれ変わったら、何になりたいですか。」\n"
"\n"
"これはまた、ずいぶんとオーソドックスな質問だ。\n"
"今さら肩の力を抜かせるような質問をする意味があるのか、\n"
"正直少し疑問に思った。\n"
"\n"
"だが、聞かれた以上は答えなければならない。\n"
"さて、どう答えようか。\n"
);

                            kaisha_point += 0;
                        } else {
                            kaisha_point += 0;
                        }

                    } else if (i==2) {
                        printf(
"「生まれ変わったら、何になりたいですか。」\n"
"\n"
"これはまた、ずいぶんオーソドックスな質問だなと思った。\n"
"そもそも今さら、肩の力を抜かせるような質問をする意味はあるのかと疑問に思う。\n"
"だが、聞かれた以上は答えなければならない。\n"
"\n"
"??さて、どう答えようか。\n"
);
                        printf("1.鳥");
                        printf("2.魚");
                        printf("まだ見ぬ生物 ");

                        if (mensetu_hentou == 1) {
                            printf(
"「鳥になりたいです。」\n"
"\n"
"私は、オーソドックスな質問に\n"
"オーソドックスな回答をしたつもりだった。\n"
"\n"
"面接官の一人が、\n"
"「なぜですか。」と聞いてきた。\n"
"\n"
"私はすかさず答えた。\n"
"\n"
"「この青く、広い空を自由に飛んでいきたいんです。\n"
"何処までも、遠くへ。\n"
"そうしたら、多分、人間になりたいと思うと思います。\n"
"\n"
"なぜなら、人間は彼らにとって\n"
"とても素敵な存在だと思うからです。\n"
"きっと私が今、鳥になりたいと思っているのと同じように、\n"
"人間に魅力を感じているのだと思います。\n"
"\n"
"私は鳥ではないので、\n"
"その魅力が何なのかは分かりません。\n"
"ですが、きっと、そう思っているはずです。」\n"
"\n"
"私の回答に、面接官達は\n"
"「ポカン」という擬音がよく似合いそうな表情を浮かべていた。\n"
"\n"
"「……ま、まぁ。」\n"
"\n"
"気を取り直すように、\n"
"面接官の一人が口を開いた。\n"

);
                            kaisha_point-=1;
                        } else if (mensetu_hentou == 2) {
                            printf(
"「魚になりたいです。」\n"
"\n"
"私はオーソドックスな質問に、\n"
"少し捻りを加えようとして??結局加えられず、\n"
"オーソドックスな回答を返した。\n"
"\n"
"すると面接官の一人が、\n"
"「なぜですか。」と、これまたオーソドックスな質問をしてきた。\n"
"\n"
"私は、このままオーソドックスに返そうと思った。\n"
"\n"
"「私、昔から金魚とか鯉とか、魚を見るのが好きで、\n"
"自分自身もいつか魚になってみたいなと思ってたんです。\n"
"泳ぐのが好きだったので、\n"
"きっと気持ちいいんだろうなと、ずっと思っていました。\n"
"\n"
"ただ、海の魚にはなりたくありません。\n"
"なぜなら、危険が多いからです。\n"
"できれば、山の上流に棲む小さな魚になりたいです。\n"
"\n"
"ただひたすらに、上を目指して泳いで生きたい。\n"
"そう思っています。\n"
"なので、魚になりたいです。」\n"
"\n"
"最後の方は、\n"
"もう自分でも何を言っているのか分からない状態だった。\n"
"だが、どうやら私の言いたいことを、\n"
"面接官達はある程度汲んでくれたようだった。\n"
"\n"
"良かった。\n"
);
                            kaisha_point+=0;


                        } else if (mensetu_hentou == 3) {
                            printf(
"「私は、まだ発見されていない生物になりたいです。」\n"
"\n"
"私は、オーソドックスな質問に、\n"
"少し尖った回答を返した。\n"
"\n"
"当然、面接官からの次の質問は\n"
"「なぜですか。」だった。\n"
"\n"
"??誰だってそう聞く。\n"
"私も、きっとそうするだろう。\n"
"\n"
"そう心の中で思いながら、\n"
"質問に対する返答を口にした。\n"
"\n"
"「私たちがまだ知らない生物ということは、\n"
"向こうも、まだ私たち人間のことを知らない可能性が高い。\n"
"つまり、彼らの住んでいる場所は、\n"
"それだけ人間の手が入っていない場所だと思うんです。\n"
"\n"
"もちろん、天敵はいるでしょうし、\n"
"安全とは言えないかもしれません。\n"
"それでも私は、そういう場所で\n"
"静かに暮らしたいと、ずっと思っていました。\n"
"\n"
"だから、まだ発見されていない生物になりたいです。」\n"
"\n"
"私の回答に、意外にも\n"
"共感の色を浮かべる面接官が多かった。\n"
"\n"
"成功なのか、失敗なのかはまだ分からない。\n"
"だが、とりあえず今は、\n"
"??成功したと思っておくことにした。\n"
);

                            kaisha_point+=2;

                        } else {
                            kaisha_point+=0;

                        }

                    }
                    printf(
"「これで面接は以上になります。お疲れ様でした。」\n"
"\n"
"そう告げられ、私はふぅっと肩を撫で下ろした。\n"
"椅子から立ち上がり、礼をして、扉を開く。\n"
"終わった後の一連の動作をやり切ったことで、\n"
"張り詰めていた緊張が、ようやくほどけていくのを感じた。\n"
"\n"
"廊下に出ると、次の人を呼びに行く。\n"
"その足取りは、面接室に入る前よりもずっと軽い。\n"
"\n"
"??これで、とりあえず今日は終了だ。\n"
"\n"
"私は、どこか現実味のない感覚のまま、\n"
"軽い足取りで帰路についた。\n"
);

                    if (kaisha_point <= 5) {
                        printf("===おめでとうございます!%dポイントのため内定を受け取りました===",kaisha_point);
                        naitei_part1 = dit;
                    } else {
                        printf("%dポイントのため内定を受け取れませんでした",kaisha_point);
                    }
                }
            }


            if (kaisha == 3) {
                kaissha_select == st.cgengo;
                printf("CyberLifeを選択しました");
                if (kaissha_select <= 60) {
                    kaisha_point += 2;
                } else {
                    kaissha_select -= 0;
                }
            }

        }

        if (gakunen == 2 && month ==5) {
            int kaisha;
            int kaissha_select = 0;
            int kaisha_point = 0;
            int mensetu_hentou =0;
            printf("\n=== 就職活動2回目 ===\n");
            printf("就職活動が始まりました。就職したい会社を選択し面接を行います。面接を通して5ポイント獲得出来たら就職できます。");
            printf("就職したい会社を選択してください");
            printf("1: MAYA");
            printf("2: 株式会社dit");
            printf("3: Cyberlife");
            printf("4: Firedragons");
            printf("5: 橋本製作所");
            printf("6: jaian");
            scanf("%d", &kaisha);
            if (kaisha == 2) {
                kaissha_select = st.linux;
                printf("株式会社ditを選択しました");
                sleep(1);
                printf("いよいよ面接が始まる。私は過去何度か経験しているが、久しぶりと言うこともありかなり緊張していた。というより久しぶりじゃなくても普通に緊張する。何故なら、面接とはその人がどれだけその会社に適応でき、その会社にどれだけ利益をもたらしてくれるかを審査する場所であり、会社にとって採用するまでの最後の砦だと思っているからだ。会社側からしたら下手な人を採用はしたくないだろう。だから向こうも真剣にこちらを見てくる。そう考えると、緊張しない方がおかしい。一人、また一人と面接室に向かっていく。その度に私の心臓は鼓動を大きく、速くしていく。寿命が縮んでいく気すらする。こんなもんをこれからもしていかないといけない可能性があると考えると、生きていくのが少し憂鬱になる。いよいよ私の番が来る。私はさらっと身だしなみの最終確認をし、待機室から出た。一連の動作をし終わり、椅子に座り、面接官と目を合わせる。いよいよ始めの質問が来る。");
                if (kaissha_select <= 60) {
                    kaisha_point += 2;
                } else {
                    kaissha_select -= 0;
                }
                for (int i = 0; i < 3; i++) {
                    if (i==0) {
                        printf("1:");
                        printf("2:");
                        printf("3:");
                        scanf("%d", &mensetu_hentou);
                        if (mensetu_hentou == 1) {
                            kaisha_point += 1;
                        } else if (mensetu_hentou == 2) {
                            kaissha_select += 1;
                        } else if (mensetu_hentou == 3) {
                            kaissha_select += 1;
                        } else {
                            kaissha_select += 0;
                        }

                    } else if (i==1) {

                    } else if (i==2) {

                    }
                    if (kaisha_point >= 5) {
                        printf("===おめでとうございます!%dポイントのため内定を受け取りました===",kaisha_point);
                        naitei_part1 = Cyberlife;
                    } else {
                        printf("%dポイントのため内定を受け取れませんでした",kaisha_point);
                    }
                }
            }


            if (kaisha == 3) {
                kaissha_select == st.cgengo;
                printf("株式会社ditを選択しました");
                if (kaissha_select <= 60) {
                    kaisha_point += 2;
                } else {
                    kaissha_select -= 0;
                }
            }

        }


        if (gakunen == 1 && month == 11) {/*進級制作*/

            int select;
            int select_seisaku = 0;

            printf("\n=== 進級制作イベント ===\n");
            printf("制作分野を選択してください\n");
            printf("1: C言語\n");
            printf("2: ITパス\n");
            printf("3: LINUX\n");
            printf("選択: ");
            scanf("%d", &select);

            if (select == 1) {
                select_seisaku = st.cgengo;
                printf("C言語を選択しました\n");
            } else if (select == 2) {
                select_seisaku = st.ipass;
                printf("ITパスを選択しました\n");
            } else if (select == 3) {
                select_seisaku = st.linux;
                printf("LINUXを選択しました\n");
            } else {
                printf("無効な選択です\n");
                select_seisaku = 0;
            }

            printf("選択分野の現在値: %d\n", select_seisaku);

            if (select_seisaku >= 60) {
                printf("進級制作 合格\n");
                printf("ストレスが 5 下がった\n");
                st.stress -= 5;
            } else {
                printf("合計値が60以上でないためダイスロールを実行します");
                int dice = rand() % 3;
                if (dice == 1) {
                    printf("進級制作 合格\n");
                    printf("ストレスが　2　下がった\n");
                    st.stress -= 2;
                } else {
                printf("進級制作 不合格\n");
                printf("ストレスが 5 上がった\n");
                st.stress += 5;
                }
            }
        }


        sleep(1);
        printf("\n--- %dか月目 終了時ステータス ---\n", month);
        printf("C言語  : %d\n", st.cgengo);
        printf("ITパス : %d\n", st.ipass);
        printf("LINUX  : %d\n", st.linux);
        printf("ストレス　：%d\n", st.stress);

        if (gakunen == 1 &&month == 12) {
            gakunen = 2;
            sleep(1);
            printf("\n========================\n");
            printf("1年間が終了しました\n");
            sleep(1);
            printf("2年生に進級しました！\n");
            printf("========================\n");

            month = 0;
        }
        if (gakunen == 2 && month == 12) { /* エピローグ */
            int select;
            int list[2];
            int count = 0;

            if (naitei_part1 == 0 && naitei_part2 == 0) {
                printf("あなたは現在一つも内定をもらっていません\n");
            } else {
                printf("あなたは以下の会社から内定をもらっています\n");

                if (naitei_part1 != 0) {
                    list[count] = naitei_part1;
                    printf("%d: ", count + 1);
                    if (naitei_part1 == MAYA) printf("MAYA\n");
                    if (naitei_part1 == Cyberlife) printf("CyberLife\n");
                    if (naitei_part1 == dit) printf("株式会社dit\n");
                    count++;
                }

                if (naitei_part2 != 0) {
                    list[count] = naitei_part2;
                    printf("%d: ", count + 1);
                    if (naitei_part2 == MAYA) printf("MAYA\n");
                    if (naitei_part2 == dit) printf("株式会社dit\n");
                    if (naitei_part2 == Cyberlife) printf("CyberLife\n");
                    count++;
                }

                printf("どの会社に就職しますか？番号を入力してください: ");
                scanf("%d", &select);

                if (select < 1 || select > count) {
                    printf("無効な選択です\n");
                } else {
                    int final_company = list[select - 1];

                    printf("あなたは ");
                    if (final_company == MAYA) printf("MAYA");
                    if (final_company == dit) printf("株式会社dit");
                    if (final_company == Cyberlife) printf("CyberLife");
                    printf(" に就職しました！\n");
                    if (final_company == Cyberlife) printf(
"私はこの2年間で培ってきた能力を上手く活かせるように、この『CyberLife』という会社を選んだ。\n"
"あれから2年??。\n"
"この会社に入ってから2年が経過した。\n"
"\n"
"私の勤めている『CyberLife』という会社は、機械開発を主としている会社で、\n"
"全員で協働して一つの製品を造り上げる会社だが、\n"
"私はこの会社に機械制御をするエンジニアとして雇われた為、\n"
"個人で作業することが多く、一人で黙々と作業出来るこの環境が\n"
"私にとってとても過ごしやすいものだった。\n"
"\n"
"初めて仕事をした日は結構キツくて、\n"
"いつ辞めてやろうかと考えていたくらいには精神的に追い詰められていた。\n"
"だが、初めて自分のプログラムで製品が上手く動いた時は、\n"
"一言で言い表せない喜びを感じ、またあの感覚を感じたい。\n"
"その一心で仕事に集中するようになった。\n"
"\n"
"今ではこの仕事にもすっかり慣れ、\n"
"上司から渡される無数の課題に追われ、\n"
"忙しいながらもそれなりに楽しい日々を送れていると感じている。\n"
"\n"
"はっきりと言おう。\n"
"私はこの会社を選んで本当に良かった。\n"
"\n"
"???? normal end.\n"
);
                    return ;
                }
            }
        }



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

