#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;

const char ans[]="1\0 1\0 3\0 5\0 11\0 21\0 43\0 85\0 171\0 341\0 683\0 1365\0 2731\0 5461\0 10923\0 21845\0 43691\0 87381\0 174763\0 349525\0 699051\0 1398101\0 2796203\0 5592405\0 11184811\0 22369621\0 44739243\0 89478485\0 178956971\0 357913941\0 715827883\0 1431655765\0 2863311531\0 5726623061\0 11453246123\0 22906492245\0 45812984491\0 91625968981\0 183251937963\0 366503875925\0 733007751851\0 1466015503701\0 2932031007403\0 5864062014805\0 11728124029611\0 23456248059221\0 46912496118443\0 93824992236885\0 187649984473771\0 375299968947541\0 750599937895083\0 1501199875790165\0 3002399751580331\0 6004799503160661\0 12009599006321323\0 24019198012642645\0 48038396025285291\0 96076792050570581\0 192153584101141163\0 384307168202282325\0 768614336404564651\0 1537228672809129301\0 3074457345618258603\0 6148914691236517205\0 12297829382473034411\0 24595658764946068821\0 49191317529892137643\0 98382635059784275285\0 196765270119568550571\0 393530540239137101141\0 787061080478274202283\0 1574122160956548404565\0 3148244321913096809131\0 6296488643826193618261\0 12592977287652387236523\0 25185954575304774473045\0 50371909150609548946091\0 100743818301219097892181\0 201487636602438195784363\0 402975273204876391568725\0 805950546409752783137451\0 1611901092819505566274901\0 3223802185639011132549803\0 6447604371278022265099605\0 12895208742556044530199211\0 25790417485112089060398421\0 51580834970224178120796843\0 103161669940448356241593685\0 206323339880896712483187371\0 412646679761793424966374741\0 825293359523586849932749483\0 1650586719047173699865498965\0 3301173438094347399730997931\0 6602346876188694799461995861\0 13204693752377389598923991723\0 26409387504754779197847983445\0 52818775009509558395695966891\0 105637550019019116791391933781\0 211275100038038233582783867563\0 422550200076076467165567735125\0 845100400152152934331135470251\0 1690200800304305868662270940501\0 3380401600608611737324541881003\0 6760803201217223474649083762005\0 13521606402434446949298167524011\0 27043212804868893898596335048021\0 54086425609737787797192670096043\0 108172851219475575594385340192085\0 216345702438951151188770680384171\0 432691404877902302377541360768341\0 865382809755804604755082721536683\0 1730765619511609209510165443073365\0 3461531239023218419020330886146731\0 6923062478046436838040661772293461\0 13846124956092873676081323544586923\0 27692249912185747352162647089173845\0 55384499824371494704325294178347691\0 110768999648742989408650588356695381\0 221537999297485978817301176713390763\0 443075998594971957634602353426781525\0 886151997189943915269204706853563051\0 1772303994379887830538409413707126101\0 3544607988759775661076818827414252203\0 7089215977519551322153637654828504405\0 14178431955039102644307275309657008811\0 28356863910078205288614550619314017621\0 56713727820156410577229101238628035243\0 113427455640312821154458202477256070485\0 226854911280625642308916404954512140971\0 453709822561251284617832809909024281941\0 907419645122502569235665619818048563883\0 1814839290245005138471331239636097127765\0 3629678580490010276942662479272194255531\0 7259357160980020553885324958544388511061\0 14518714321960041107770649917088777022123\0 29037428643920082215541299834177554044245\0 58074857287840164431082599668355108088491\0 116149714575680328862165199336710216176981\0 232299429151360657724330398673420432353963\0 464598858302721315448660797346840864707925\0 929197716605442630897321594693681729415851\0 1858395433210885261794643189387363458831701\0 3716790866421770523589286378774726917663403\0 7433581732843541047178572757549453835326805\0 14867163465687082094357145515098907670653611\0 29734326931374164188714291030197815341307221\0 59468653862748328377428582060395630682614443\0 118937307725496656754857164120791261365228885\0 237874615450993313509714328241582522730457771\0 475749230901986627019428656483165045460915541\0 951498461803973254038857312966330090921831083\0 1902996923607946508077714625932660181843662165\0 3805993847215893016155429251865320363687324331\0 7611987694431786032310858503730640727374648661\0 15223975388863572064621717007461281454749297323\0 30447950777727144129243434014922562909498594645\0 60895901555454288258486868029845125818997189291\0 121791803110908576516973736059690251637994378581\0 243583606221817153033947472119380503275988757163\0 487167212443634306067894944238761006551977514325\0 974334424887268612135789888477522013103955028651\0 1948668849774537224271579776955044026207910057301\0 3897337699549074448543159553910088052415820114603\0 7794675399098148897086319107820176104831640229205\0 15589350798196297794172638215640352209663280458411\0 31178701596392595588345276431280704419326560916821\0 62357403192785191176690552862561408838653121833643\0 124714806385570382353381105725122817677306243667285\0 249429612771140764706762211450245635354612487334571\0 498859225542281529413524422900491270709224974669141\0 997718451084563058827048845800982541418449949338283\0 1995436902169126117654097691601965082836899898676565\0 3990873804338252235308195383203930165673799797353131\0 7981747608676504470616390766407860331347599594706261\0 15963495217353008941232781532815720662695199189412523\0 31926990434706017882465563065631441325390398378825045\0 63853980869412035764931126131262882650780796757650091\0 127707961738824071529862252262525765301561593515300181\0 255415923477648143059724504525051530603123187030600363\0 510831846955296286119449009050103061206246374061200725\0 1021663693910592572238898018100206122412492748122401451\0 2043327387821185144477796036200412244824985496244802901\0 4086654775642370288955592072400824489649970992489605803\0 8173309551284740577911184144801648979299941984979211605\0 16346619102569481155822368289603297958599883969958423211\0 32693238205138962311644736579206595917199767939916846421\0 65386476410277924623289473158413191834399535879833692843\0 130772952820555849246578946316826383668799071759667385685\0 261545905641111698493157892633652767337598143519334771371\0 523091811282223396986315785267305534675196287038669542741\0 1046183622564446793972631570534611069350392574077339085483\0 2092367245128893587945263141069222138700785148154678170965\0 4184734490257787175890526282138444277401570296309356341931\0 8369468980515574351781052564276888554803140592618712683861\0 16738937961031148703562105128553777109606281185237425367723\0 33477875922062297407124210257107554219212562370474850735445\0 66955751844124594814248420514215108438425124740949701470891\0 133911503688249189628496841028430216876850249481899402941781\0 267823007376498379256993682056860433753700498963798805883563\0 535646014752996758513987364113720867507400997927597611767125\0 1071292029505993517027974728227441735014801995855195223534251\0 2142584059011987034055949456454883470029603991710390447068501\0 4285168118023974068111898912909766940059207983420780894137003\0 8570336236047948136223797825819533880118415966841561788274005\0 17140672472095896272447595651639067760236831933683123576548011\0 34281344944191792544895191303278135520473663867366247153096021\0 68562689888383585089790382606556271040947327734732494306192043\0 137125379776767170179580765213112542081894655469464988612384085\0 274250759553534340359161530426225084163789310938929977224768171\0 548501519107068680718323060852450168327578621877859954449536341\0 1097003038214137361436646121704900336655157243755719908899072683\0 2194006076428274722873292243409800673310314487511439817798145365\0 4388012152856549445746584486819601346620628975022879635596290731\0 8776024305713098891493168973639202693241257950045759271192581461\0 17552048611426197782986337947278405386482515900091518542385162923\0 35104097222852395565972675894556810772965031800183037084770325845\0 70208194445704791131945351789113621545930063600366074169540651691\0 140416388891409582263890703578227243091860127200732148339081303381\0 280832777782819164527781407156454486183720254401464296678162606763\0 561665555565638329055562814312908972367440508802928593356325213525\0 1123331111131276658111125628625817944734881017605857186712650427051\0 2246662222262553316222251257251635889469762035211714373425300854101\0 4493324444525106632444502514503271778939524070423428746850601708203\0 8986648889050213264889005029006543557879048140846857493701203416405\0 17973297778100426529778010058013087115758096281693714987402406832811\0 35946595556200853059556020116026174231516192563387429974804813665621\0 71893191112401706119112040232052348463032385126774859949609627331243\0 143786382224803412238224080464104696926064770253549719899219254662485\0 287572764449606824476448160928209393852129540507099439798438509324971\0 575145528899213648952896321856418787704259081014198879596877018649941\0 1150291057798427297905792643712837575408518162028397759193754037299883\0 2300582115596854595811585287425675150817036324056795518387508074599765\0 4601164231193709191623170574851350301634072648113591036775016149199531\0 9202328462387418383246341149702700603268145296227182073550032298399061\0 18404656924774836766492682299405401206536290592454364147100064596798123\0 36809313849549673532985364598810802413072581184908728294200129193596245\0 73618627699099347065970729197621604826145162369817456588400258387192491\0 147237255398198694131941458395243209652290324739634913176800516774384981\0 294474510796397388263882916790486419304580649479269826353601033548769963\0 588949021592794776527765833580972838609161298958539652707202067097539925\0 1177898043185589553055531667161945677218322597917079305414404134195079851\0 2355796086371179106111063334323891354436645195834158610828808268390159701\0 4711592172742358212222126668647782708873290391668317221657616536780319403\0 9423184345484716424444253337295565417746580783336634443315233073560638805\0 18846368690969432848888506674591130835493161566673268886630466147121277611\0 37692737381938865697777013349182261670986323133346537773260932294242555221\0 75385474763877731395554026698364523341972646266693075546521864588485110443\0 150770949527755462791108053396729046683945292533386151093043729176970220885\0 301541899055510925582216106793458093367890585066772302186087458353940441771\0 603083798111021851164432213586916186735781170133544604372174916707880883541\0 1206167596222043702328864427173832373471562340267089208744349833415761767083\0 ";

const int st[]={0,3,6,9,12,16,20,24,28,33,38,43,49,55,61,68,75,82,89,97,105,113,122,131,140,150,160,170,180,191,202,213,225,237,249,262,275,288,301,315,329,343,358,373,388,404,420,436,452,469,486,503,521,539,557,576,595,614,633,653,673,693,714,735,756,778,800,822,844,867,890,913,937,961,985,1010,1035,1060,1086,1112,1138,1164,1191,1218,1245,1273,1301,1329,1358,1387,1416,1445,1475,1505,1535,1566,1597,1628,1660,1692,1724,1756,1789,1822,1855,1889,1923,1957,1992,2027,2062,2097,2133,2169,2205,2242,2279,2316,2354,2392,2430,2468,2507,2546,2585,2625,2665,2705,2746,2787,2828,2869,2911,2953,2995,3038,3081,3124,3168,3212,3256,3300,3345,3390,3435,3481,3527,3573,3620,3667,3714,3761,3809,3857,3905,3954,4003,4052,4102,4152,4202,4252,4303,4354,4405,4457,4509,4561,4614,4667,4720,4773,4827,4881,4935,4990,5045,5100,5156,5212,5268,5325,5382,5439,5496,5554,5612,5670,5729,5788,5847,5907,5967,6027,6087,6148,6209,6270,6332,6394,6456,6519,6582,6645,6708,6772,6836,6900,6965,7030,7095,7161,7227,7293,7359,7426,7493,7560,7628,7696,7764,7833,7902,7971,8040,8110,8180,8250,8321,8392,8463,8535,8607,8679,8751,8824,8897,8970,9044,9118,9192,9267,9342,9417,9492,9568,9644,9720,9797,9874,9951};

int n;

int main(void){
	while(scanf("%d",&n)!=EOF)
		puts(ans+st[n]);
	return 0;
}