#define _CRT_SECURE_NO_WARNING
#include <bits/stdc++.h>
#include <cassert>
#include <x86intrin.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define repair(x) x.erase(unique(all(x)),x.end())
#define pb push_back
using namespace std;
typedef unsigned long long ll; //long long. or use int64_t
typedef long double ld; //long double
const int iinf = 1e9; //integer maximum
const long long linf = 1e18; //long long maximum
//const int mod = 1e9 + 9; //prime number
template<class T>T gcd(T x, T y){if (!y)return x;return gcd(y,x%y);}
template<class T>T lcm(T x, T y){return (x*y)/gcd(x,y);}
template<class T>T bitcnt(T x){return __builtin_popcount(x);}
template<class T>T bitpar(T x){return __builtin_parity(x);}
template<class T>T bitclz(T x){return __builtin_clz(x);}
template<class T>T bitctz(T x){return __builtin_ctz(x);}
int main() {
	fastio;
    int n;
    cin>>n;
    if(n==0)cout<<"ONTAK 2010";
    if(n==1){
        vector<pair<char,int>>a;
        a.pb({'G',2932});a.pb({'o',2931});a.pb({'d',2928});a.pb({'z',2923});a.pb({'i',2916});a.pb({'l',5803});a.pb({'a',2883});a.pb({' ',2868});a.pb({'t',2851});a.pb({'e',2832});a.pb({'r',5599});a.pb({'o',2763});a.pb({'r',2736});a.pb({'i',2707});a.pb({'z',2676});a.pb({'e',2643});a.pb({'s',2608});a.pb({' ',2571});a.pb({'B',2532});a.pb({'a',2491});a.pb({'j',2448});a.pb({'t',2403});a.pb({'o',2356});a.pb({'l',2307});a.pb({'y',2256});a.pb({' ',2203});a.pb({'l',2148});a.pb({'o',2091});a.pb({'w',2032});a.pb({'e',1971});a.pb({'r',1908});a.pb({' ',1843});a.pb({'a',1776});a.pb({'g',1707});a.pb({'a',1636});a.pb({'i',1563});a.pb({'n',1488});a.pb({'.',1411});a.pb({' ',1332});a.pb({'E',1251});a.pb({'v',1168});a.pb({'e',1083});a.pb({'r',996});a.pb({'y',907});a.pb({' ',816});a.pb({'d',723});a.pb({'a',628});a.pb({'y',531});a.pb({' ',432});a.pb({'a',331});a.pb({' ',228});a.pb({'m',123});a.pb({'o',16});a.pb({'n',2839});a.pb({'s',2728});a.pb({'t',2615});a.pb({'e',2500});a.pb({'r',2383});a.pb({' ',2264});a.pb({'c',2143});a.pb({'o',2020});a.pb({'m',1895});a.pb({'e',1768});a.pb({'s',1639});a.pb({' ',1508});a.pb({'o',1375});a.pb({'u',1240});a.pb({'t',1103});a.pb({' ',964});a.pb({'o',823});a.pb({'f',680});a.pb({' ',535});a.pb({'t',388});a.pb({'h',239});a.pb({'e',88});a.pb({' ',2867});a.pb({'o',2712});a.pb({'c',2555});a.pb({'e',2396});a.pb({'a',2235});a.pb({'n',2072});a.pb({',',1907});a.pb({' ',1740});a.pb({'s',1571});a.pb({'l',1400});a.pb({'o',1227});a.pb({'w',1052});a.pb({' ',875});a.pb({'m',696});a.pb({'o',515});a.pb({'v',332});a.pb({'e',147});a.pb({'m',2892});a.pb({'e',2703});a.pb({'n',2512});a.pb({'t',2319});a.pb({' ',2124});a.pb({'o',1927});a.pb({'f',1728});a.pb({' ',1527});a.pb({'m',1324});a.pb({'a',1119});a.pb({'r',912});a.pb({'c',703});a.pb({'h',492});a.pb({'i',279});a.pb({'n',64});a.pb({'g',2779});a.pb({' ',2560});a.pb({'t',2339});a.pb({'h',2116});a.pb({'r',1891});a.pb({'o',1664});a.pb({'u',1435});a.pb({'g',1204});a.pb({'h',971});a.pb({' ',736});a.pb({'t',499});a.pb({'h',260});a.pb({'e',19});a.pb({' ',2708});a.pb({'c',2463});a.pb({'i',2216});a.pb({'t',1967});a.pb({'y',1716});a.pb({' ',1463});a.pb({'t',1208});a.pb({'o',951});a.pb({' ',692});a.pb({'s',431});a.pb({'o',168});a.pb({'m',2835});a.pb({'e',2568});a.pb({' ',2299});a.pb({'o',2028});a.pb({'f',1755});a.pb({' ',1480});a.pb({'t',1203});a.pb({'h',924});a.pb({'e',643});a.pb({' ',360});a.pb({'s',75});a.pb({'k',2720});a.pb({'y',2431});a.pb({'s',2140});a.pb({'c',1847});a.pb({'r',1552});a.pb({'a',1255});a.pb({'p',956});a.pb({'e',655});a.pb({'r',352});a.pb({'s',47});a.pb({' ',2672});a.pb({'a',2363});a.pb({'n',2052});a.pb({'d',1739});a.pb({' ',1424});a.pb({'e',1107});a.pb({'a',788});a.pb({'t',467});a.pb({'s',144});a.pb({' ',2751});a.pb({'i',2424});a.pb({'t',2095});a.pb({' ',1764});a.pb({'w',1431});a.pb({'i',1096});a.pb({'t',759});a.pb({'h',420});a.pb({' ',79});a.pb({'p',2668});a.pb({'e',2323});a.pb({'o',1976});a.pb({'p',1627});a.pb({'l',1276});a.pb({'e',923});a.pb({' ',568});a.pb({'w',211});a.pb({'h',2784});a.pb({'o',2423});a.pb({' ',2060});a.pb({'a',1695});a.pb({'r',1328});a.pb({'e',959});a.pb({' ',588});a.pb({'i',215});a.pb({'n',2772});a.pb({' ',2395});a.pb({'i',2016});a.pb({'t',1635});a.pb({'.',1252});a.pb({' ',867});a.pb({'E',480});a.pb({'a',91});a.pb({'t',2632});a.pb({'i',2239});a.pb({'n',1844});a.pb({'g',1447});a.pb({' ',1048});a.pb({'o',647});a.pb({'n',244});a.pb({'e',2771});a.pb({' ',2364});a.pb({'s',1955});a.pb({'k',1544});a.pb({'y',1131});a.pb({'s',716});a.pb({'c',299});a.pb({'r',2812});a.pb({'a',2391});a.pb({'p',1968});a.pb({'e',1543});a.pb({'r',1116});a.pb({' ',687});a.pb({'t',256});a.pb({'a',2755});a.pb({'k',2320});a.pb({'e',1883});a.pb({'s',1444});a.pb({' ',1003});a.pb({'t',560});a.pb({'h',115});a.pb({'e',2600});a.pb({' ',2151});a.pb({'w',1700});a.pb({'h',1247});a.pb({'o',792});a.pb({'l',335});a.pb({'e',2808});a.pb({' ',2347});a.pb({'d',1884});a.pb({'a',1419});a.pb({'y',952});a.pb({',',483});a.pb({' ',12});a.pb({'a',2471});a.pb({'t',1996});a.pb({' ',1519});a.pb({'d',1040});a.pb({'u',559});a.pb({'s',76});a.pb({'k',2523});a.pb({',',2036});a.pb({' ',1547});a.pb({'i',1056});a.pb({'t',563});a.pb({' ',68});a.pb({'r',2503});a.pb({'e',2004});a.pb({'t',1503});a.pb({'u',1000});a.pb({'r',495});a.pb({'n',2920});a.pb({'s',2411});a.pb({' ',1900});a.pb({'t',1387});a.pb({'o',872});a.pb({' ',355});a.pb({'i',2768});a.pb({'t',2247});a.pb({'s',1724});a.pb({' ',1199});a.pb({'h',672});a.pb({'i',143});a.pb({'d',2544});a.pb({'i',2011});a.pb({'n',1476});a.pb({'g',939});a.pb({' ',400});a.pb({'p',2791});a.pb({'l',2248});a.pb({'a',1703});a.pb({'c',1156});a.pb({'e',607});a.pb({' ',56});a.pb({'h',2435});a.pb({'i',1880});a.pb({'d',2087});a.pb({'e',203});a.pb({'n',2572});a.pb({' ',2007});a.pb({'i',1440});a.pb({'n',871});a.pb({' ',300});a.pb({'t',2659});a.pb({'h',2084});a.pb({'e',1507});a.pb({' ',928});a.pb({'d',347});a.pb({'e',2696});a.pb({'p',2111});a.pb({'t',1524});a.pb({'h',935});a.pb({'s',344});a.pb({'.',2683});a.pb({' ',2088});a.pb({'T',1491});a.pb({'o',892});a.pb({' ',291});a.pb({'m',2620});a.pb({'a',2015});a.pb({'k',1408});a.pb({'e',799});a.pb({' ',188});a.pb({'m',2507});a.pb({'a',1892});a.pb({'t',1931});a.pb({'e',35});a.pb({'r',2344});a.pb({'s',1719});a.pb({' ',1092});a.pb({'w',463});a.pb({'o',2764});a.pb({'r',2131});a.pb({'s',1496});a.pb({'e',859});a.pb({',',220});a.pb({' ',2511});a.pb({'g',1868});a.pb({'o',1223});a.pb({'i',576});a.pb({'n',2859});a.pb({'g',2208});a.pb({' ',1555});a.pb({'t',900});a.pb({'h',243});a.pb({'r',2516});a.pb({'o',1855});a.pb({'u',1192});a.pb({'g',527});a.pb({'h',2792});a.pb({' ',2123});a.pb({'t',1452});a.pb({'h',779});a.pb({'e',104});a.pb({' ',2359});a.pb({'c',1680});a.pb({'i',999});a.pb({'t',316});a.pb({'y',2563});a.pb({',',1876});a.pb({' ',1187});a.pb({'G',496});a.pb({'o',2735});a.pb({'d',2040});a.pb({'z',1343});a.pb({'i',644});a.pb({'l',5047});a.pb({'a',1467});a.pb({' ',760});a.pb({'w',51});a.pb({'a',2272});a.pb({'g',1559});a.pb({'s',844});a.pb({' ',127});a.pb({'i',2340});a.pb({'t',1619});a.pb({'s',896});a.pb({' ',171});a.pb({'t',2376});a.pb({'a',1647});a.pb({'i',916});a.pb({'l',183});a.pb({' ',2380});a.pb({'a',1643});a.pb({'n',904});a.pb({'d',163});a.pb({' ',2352});a.pb({'d',1607});a.pb({'e',860});a.pb({'s',111});a.pb({'t',2292});a.pb({'r',1539});a.pb({'o',784});a.pb({'y',27});a.pb({'s',2200});a.pb({' ',1439});a.pb({'t',676});a.pb({'o',2843});a.pb({'w',2076});a.pb({'e',1307});a.pb({'r',536});a.pb({'s',2695});a.pb({',',1920});a.pb({' ',1143});a.pb({'n',364});a.pb({'e',2515});a.pb({'a',1732});a.pb({'r',947});a.pb({' ',160});a.pb({'t',2303});a.pb({'h',1512});a.pb({'e',719});a.pb({' ',2856});a.pb({'p',2059});a.pb({'a',1260});a.pb({'s',3047});a.pb({'e',1783});a.pb({'s',976});a.pb({'.',167});a.pb({' ',2288});a.pb({'T',1475});a.pb({'h',660});a.pb({'e',2775});a.pb({' ',1956});a.pb({'p',1135});a.pb({'r',312});a.pb({'o',2419});a.pb({'s',1592});a.pb({'p',763});a.pb({'e',2864});a.pb({'c',2031});a.pb({'t',1196});a.pb({' ',359});a.pb({'o',2452});a.pb({'f',1611});a.pb({' ',768});a.pb({'b',2855});a.pb({'e',2008});a.pb({'c',1159});a.pb({'o',308});a.pb({'m',2387});a.pb({'i',1532});a.pb({'n',675});a.pb({'g',2748});a.pb({' ',1887});a.pb({'a',1024});a.pb({' ',159});a.pb({'m',2224});a.pb({'e',1355});a.pb({'a',484});a.pb({'l',2543});a.pb({' ',1668});a.pb({'f',791});a.pb({'o',2844});a.pb({'r',1963});a.pb({' ',1080});a.pb({'a',195});a.pb({'n',2240});a.pb({' ',1351});a.pb({'u',460});a.pb({'n',2499});a.pb({'d',1604});a.pb({'e',707});a.pb({'r',2740});a.pb({'w',1839});a.pb({'a',936});a.pb({'t',31});a.pb({'e',2056});a.pb({'r',1147});a.pb({' ',236});a.pb({'m',2255});a.pb({'o',1340});a.pb({'n',423});a.pb({'s',2436});a.pb({'t',1515});a.pb({'e',592});a.pb({'r',2599});a.pb({',',1672});a.pb({' ',743});a.pb({'t',2744});a.pb({'o',1811});a.pb({' ',876});a.pb({'d',2871});a.pb({'i',1932});a.pb({'s',991});a.pb({'c',48});a.pb({'o',2035});a.pb({'u',1088});a.pb({'r',139});a.pb({'a',2120});a.pb({'g',1167});a.pb({'e',212});a.pb({' ',2187});a.pb({'s',1228});a.pb({'o',267});a.pb({'m',2236});a.pb({'e',1271});a.pb({' ',304});a.pb({'r',2267});a.pb({'e',1296});a.pb({'s',323});a.pb({'i',2280});a.pb({'d',1303});a.pb({'e',324});a.pb({'n',2275});a.pb({'t',1292});a.pb({'s',307});a.pb({' ',2252});a.pb({'s',1263});a.pb({'p',272});a.pb({'e',2211});a.pb({'n',1216});a.pb({'t',219});a.pb({' ',2152});a.pb({'i',1151});a.pb({'n',148});a.pb({' ',2075});a.pb({'u',1068});a.pb({'n',59});a.pb({'c',1980});a.pb({'o',967});a.pb({'m',2884});a.pb({'f',1867});a.pb({'o',848});a.pb({'r',2759});a.pb({'t',1736});a.pb({'-',711});a.pb({' ',2616});a.pb({'t',1587});a.pb({'i',556});a.pb({'o',2455});a.pb({'n',1420});a.pb({' ',383});a.pb({'i',2276});a.pb({'n',1235});a.pb({' ',192});a.pb({'t',2079});a.pb({'h',1032});a.pb({'e',2915});a.pb({' ',1864});a.pb({'c',811});a.pb({'i',2688});a.pb({'t',1631});a.pb({'y',572});a.pb({'.',2443});a.pb({' ',1380});a.pb({'D',315});a.pb({'u',2180});a.pb({'r',1111});a.pb({'i',40});a.pb({'n',1899});a.pb({'g',824});a.pb({' ',2679});a.pb({'t',1600});a.pb({'h',519});a.pb({'e',2368});a.pb({' ',1283});a.pb({'n',196});a.pb({'i',2039});a.pb({'g',948});a.pb({'h',2787});a.pb({'t',1692});a.pb({' ',595});a.pb({'o',2428});a.pb({'f',1327});a.pb({' ',224});a.pb({'e',2051});a.pb({'a',944});a.pb({'c',2767});a.pb({'h',1656});a.pb({' ',543});a.pb({'t',2360});a.pb({'o',1243});a.pb({'w',124});a.pb({'e',1935});a.pb({'r',812});a.pb({' ',2619});a.pb({'i',1492});a.pb({'s',363});a.pb({' ',2164});a.pb({'d',1031});a.pb({'e',2828});a.pb({'r',1691});a.pb({'i',552});a.pb({'v',2343});a.pb({'e',1200});a.pb({'d',55});a.pb({' ',1840});a.pb({'a',691});a.pb({'s',2472});a.pb({' ',1319});a.pb({'a',164});a.pb({' ',1939});a.pb({'r',780});a.pb({'e',2551});a.pb({'s',1388});a.pb({'i',223});a.pb({'d',1988});a.pb({'e',819});a.pb({'n',2580});a.pb({'t',1407});a.pb({' ',232});a.pb({'a',1987});a.pb({'n',808});a.pb({'d',2559});a.pb({' ',1376});a.pb({'f',191});a.pb({'l',1936});a.pb({'e',3235});a.pb({'s',1295});a.pb({' ',100});a.pb({'t',1835});a.pb({'o',636});a.pb({' ',2367});a.pb({'t',1164});a.pb({'h',2891});a.pb({'e',1684});a.pb({' ',475});a.pb({'c',2196});a.pb({'o',983});a.pb({'u',2700});a.pb({'n',1483});a.pb({'t',264});a.pb({'r',1975});a.pb({'y',752});a.pb({'s',2459});a.pb({'i',1232});a.pb({'d',3});a.pb({'e',1704});a.pb({'.',471});a.pb({' ',2168});a.pb({'I',931});a.pb({'n',2624});a.pb({' ',1383});a.pb({'B',140});a.pb({'a',1827});a.pb({'j',580});a.pb({'t',2263});a.pb({'o',1012});a.pb({'g',2691});a.pb({'r',1436});a.pb({'o',179});a.pb({'d',1852});a.pb({'z',591});a.pb({'i',2260});a.pb({'e',995});a.pb({' ',2660});a.pb({'s',1391});a.pb({'k',120});a.pb({'y',1779});a.pb({'s',504});a.pb({'c',2159});a.pb({'r',880});a.pb({'a',2531});a.pb({'p',1248});a.pb({'e',2895});a.pb({'r',1608});a.pb({'s',319});a.pb({' ',1960});a.pb({'w',667});a.pb({'e',2304});a.pb({'r',1007});a.pb({'e',2640});a.pb({' ',1339});a.pb({'b',36});a.pb({'u',1663});a.pb({'i',356});a.pb({'l',1979});a.pb({'t',668});a.pb({' ',2287});a.pb({'o',972});a.pb({'n',2587});a.pb({'l',1268});a.pb({'y',2879});a.pb({' ',1556});a.pb({'a',231});a.pb({'t',1836});a.pb({' ',507});a.pb({'s',2108});a.pb({'t',775});a.pb({'r',2372});a.pb({'e',3663});a.pb({'t',1287});a.pb({' ',2876});a.pb({'c',1531});a.pb({'r',184});a.pb({'o',1767});a.pb({'s',2411});a.pb({'i',640});a.pb({'n',2215});a.pb({'g',856});a.pb({'s',2427});a.pb({'.',1064});a.pb({' ',2631});a.pb({'A',1264});a.pb({'t',2827});a.pb({' ',1456});a.pb({'e',83});a.pb({'a',1640});a.pb({'c',263});a.pb({'h',1816});a.pb({' ',435});a.pb({'i',1984});a.pb({'n',599});a.pb({'t',2144});a.pb({'e',755});a.pb({'r',2296});a.pb({'s',903});a.pb({'e',2440});a.pb({'c',1043});a.pb({'t',2576});a.pb({'i',1175});a.pb({'o',2704});a.pb({'n',1299});a.pb({' ',2824});a.pb({'t',1415});a.pb({'h',4});a.pb({'e',1523});a.pb({'r',108});a.pb({'e',1623});a.pb({' ',204});a.pb({'i',1715});a.pb({'s',292});a.pb({' ',1799});a.pb({'e',372});a.pb({'x',1875});a.pb({'a',444});a.pb({'c',1943});a.pb({'t',508});a.pb({'l',2003});a.pb({'y',564});a.pb({' ',2055});a.pb({'o',612});a.pb({'n',2099});a.pb({'e',652});a.pb({' ',2135});a.pb({'b',684});a.pb({'u',2163});a.pb({'i',708});a.pb({'l',2183});a.pb({'d',724});a.pb({'i',2195});a.pb({'n',732});a.pb({'g',2199});a.pb({'.',732});a.pb({' ',2195});a.pb({'J',724});a.pb({'u',2183});a.pb({'n',708});a.pb({'c',2163});a.pb({'t',684});a.pb({'i',2135});a.pb({'o',652});a.pb({'n',2099});a.pb({'s',612});a.pb({' ',2055});a.pb({'a',564});a.pb({'r',2003});a.pb({'e',508});a.pb({' ',1943});a.pb({'c',444});a.pb({'o',1875});a.pb({'n',2171});a.pb({'e',292});a.pb({'c',1715});a.pb({'t',204});a.pb({'e',1623});a.pb({'d',108});a.pb({' ',1523});a.pb({'b',4});a.pb({'y',1415});a.pb({' ',2824});a.pb({'t',1299});a.pb({'w',2704});a.pb({'o',1175});a.pb({'-',2576});a.pb({'w',1043});a.pb({'a',2440});a.pb({'y',903});a.pb({' ',2296});a.pb({'s',755});a.pb({'t',2144});a.pb({'r',599});a.pb({'e',2419});a.pb({'t',1816});a.pb({'s',263});a.pb({'.',1640});a.pb({' ',83});a.pb({'I',1456});a.pb({'n',2827});a.pb({' ',1264});a.pb({'a',2631});a.pb({'d',3491});a.pb({'i',856});a.pb({'t',2215});a.pb({'i',640});a.pb({'o',1995});a.pb({'n',416});a.pb({',',1767});a.pb({' ',184});a.pb({'a',1531});a.pb({' ',2876});a.pb({'t',1287});a.pb({'h',2628});a.pb({'e',1035});a.pb({' ',2372});a.pb({'j',775});a.pb({'u',2108});a.pb({'n',507});a.pb({'c',1836});a.pb({'t',231});a.pb({'i',1556});a.pb({'o',2879});a.pb({'n',1268});a.pb({' ',2587});a.pb({'i',972});a.pb({'s',2287});a.pb({' ',668});a.pb({'j',1979});a.pb({'u',356});a.pb({'s',1663});a.pb({'t',36});a.pb({' ',1339});a.pb({'a',2640});a.pb({'b',1007});a.pb({'o',2304});a.pb({'v',667});a.pb({'e',1960});a.pb({' ',319});a.pb({'t',1608});a.pb({'h',2895});a.pb({'e',1248});a.pb({' ',2531});a.pb({'o',880});a.pb({'c',2159});a.pb({'e',504});a.pb({'a',1779});a.pb({'n',120});a.pb({',',1391});a.pb({' ',2660});a.pb({'t',995});a.pb({'h',2260});a.pb({'i',591});a.pb({'s',1852});a.pb({' ',179});a.pb({'i',1436});a.pb({'s',2691});a.pb({' ',1012});a.pb({'w',2263});a.pb({'h',580});a.pb({'e',1827});a.pb({'r',140});a.pb({'e',1383});a.pb({' ',2624});a.pb({'G',931});a.pb({'o',2168});a.pb({'d',471});a.pb({'z',1704});a.pb({'i',3});a.pb({'l',3691});a.pb({'a',752});a.pb({' ',1975});a.pb({'b',264});a.pb({'e',1483});a.pb({'g',2700});a.pb({'i',983});a.pb({'n',2196});a.pb({'s',475});a.pb({' ',1684});a.pb({'i',2891});a.pb({'t',1164});a.pb({'s',2367});a.pb({' ',636});a.pb({'d',1835});a.pb({'e',100});a.pb({'s',1295});a.pb({'t',2488});a.pb({'r',747});a.pb({'u',1936});a.pb({'c',191});a.pb({'t',1376});a.pb({'i',2559});a.pb({'v',808});a.pb({'e',1987});a.pb({' ',232});a.pb({'j',1407});a.pb({'o',2580});a.pb({'u',819});a.pb({'r',1988});a.pb({'n',223});a.pb({'e',1388});a.pb({'y',2551});a.pb({' ',780});a.pb({'t',1939});a.pb({'h',164});a.pb({'r',1319});a.pb({'o',2472});a.pb({'u',691});a.pb({'g',1840});a.pb({'h',55});a.pb({' ',1200});a.pb({'t',2343});a.pb({'h',552});a.pb({'e',1691});a.pb({' ',2828});a.pb({'c',1031});a.pb({'i',2164});a.pb({'t',363});a.pb({'y',1492});a.pb({'.',2619});a.pb({' ',812});a.pb({'D',1935});a.pb({'u',124});a.pb({'r',1243});a.pb({'i',2360});a.pb({'n',543});a.pb({'g',1656});a.pb({' ',2767});a.pb({'t',944});a.pb({'h',2051});a.pb({'e',224});a.pb({' ',1327});a.pb({'i',2428});a.pb({'n',595});a.pb({'v',1692});a.pb({'e',2787});a.pb({'s',948});a.pb({'t',2039});a.pb({'i',196});a.pb({'g',1283});a.pb({'a',2368});a.pb({'t',519});a.pb({'i',1600});a.pb({'o',2679});a.pb({'n',824});a.pb({',',1899});a.pb({' ',40});a.pb({'t',1111});a.pb({'h',2180});a.pb({'e',315});a.pb({' ',1380});a.pb({'m',2443});a.pb({'o',572});a.pb({'n',1631});a.pb({'s',2688});a.pb({'t',811});a.pb({'e',1864});a.pb({'r',2915});a.pb({' ',1032});a.pb({'m',2079});a.pb({'o',192});a.pb({'v',1235});a.pb({'e',2276});a.pb({'s',383});a.pb({' ',1420});a.pb({'o',2455});a.pb({'n',556});a.pb({'l',1587});a.pb({'y',2616});a.pb({' ',711});a.pb({'i',1736});a.pb({'n',2759});a.pb({' ',848});a.pb({'t',1867});a.pb({'h',2884});a.pb({'e',967});a.pb({' ',1980});a.pb({'s',59});a.pb({'t',1068});a.pb({'r',2075});a.pb({'e',1299});a.pb({'t',2152});a.pb({'s',219});a.pb({'.',1216});a.pb({' ',2211});a.pb({'G',272});a.pb({'o',1263});a.pb({'d',2252});a.pb({'z',307});a.pb({'i',1292});a.pb({'l',2599});a.pb({'a',1303});a.pb({' ',2280});a.pb({'n',323});a.pb({'o',1296});a.pb({'t',2267});a.pb({'e',304});a.pb({'d',1271});a.pb({' ',2236});a.pb({'t',267});a.pb({'h',1228});a.pb({'a',2187});a.pb({'t',212});a.pb({' ',1167});a.pb({'h',2120});a.pb({'e',139});a.pb({' ',1088});a.pb({'m',2035});a.pb({'u',48});a.pb({'s',991});a.pb({'t',1932});a.pb({' ',2871});a.pb({'h',876});a.pb({'u',1811});a.pb({'r',3487});a.pb({'y',1672});a.pb({' ',2599});a.pb({'u',592});a.pb({'p',1515});a.pb({' ',2436});a.pb({'w',423});a.pb({'i',1340});a.pb({'t',2255});a.pb({'h',236});a.pb({' ',1147});a.pb({'t',2056});a.pb({'h',31});a.pb({'e',936});a.pb({' ',1839});a.pb({'c',2740});a.pb({'o',707});a.pb({'n',1604});a.pb({'s',2499});a.pb({'u',460});a.pb({'m',1351});a.pb({'p',2240});a.pb({'t',195});a.pb({'i',1080});a.pb({'o',1963});a.pb({'n',2844});a.pb({' ',791});a.pb({'o',1668});a.pb({'f',2543});a.pb({' ',484});a.pb({'r',1355});a.pb({'e',2224});a.pb({'s',159});a.pb({'i',1024});a.pb({'d',1887});a.pb({'e',2748});a.pb({'n',675});a.pb({'t',1532});a.pb({'s',2387});a.pb({' ',308});a.pb({'a',1159});a.pb({'n',2008});a.pb({'d',2855});a.pb({' ',768});a.pb({'c',1611});a.pb({'a',2452});a.pb({'r',359});a.pb({'e',1196});a.pb({'f',2031});a.pb({'u',2864});a.pb({'l',2355});a.pb({'y',2419});a.pb({' ',312});a.pb({'c',1135});a.pb({'h',1956});a.pb({'o',3435});a.pb({'s',1475});a.pb({'e',2288});a.pb({' ',167});a.pb({'t',976});a.pb({'h',1783});a.pb({'e',2588});a.pb({' ',459});a.pb({'s',1260});a.pb({'k',2059});a.pb({'y',2856});a.pb({'s',719});a.pb({'c',1512});a.pb({'r',2303});a.pb({'a',160});a.pb({'p',947});a.pb({'e',1732});a.pb({'r',2515});a.pb({'s',364});a.pb({' ',1143});a.pb({'d',1920});a.pb({'e',2695});a.pb({'v',536});a.pb({'o',1307});a.pb({'u',2076});a.pb({'r',2843});a.pb({'i',676});a.pb({'n',1439});a.pb({'g',2200});a.pb({' ',27});a.pb({'a',784});a.pb({'n',1539});a.pb({'d',2292});a.pb({' ',111});a.pb({'s',860});a.pb({'t',1607});a.pb({'r',2352});a.pb({'e',1067});a.pb({'t',1643});a.pb({'s',2380});a.pb({',',183});a.pb({' ',916});a.pb({'w',1647});a.pb({'h',2376});a.pb({'i',171});a.pb({'c',896});a.pb({'h',1619});a.pb({' ',2340});a.pb({'r',127});a.pb({'e',844});a.pb({'a',1559});a.pb({'c',2272});a.pb({'h',51});a.pb({'e',760});a.pb({'s',1467});a.pb({' ',2172});a.pb({'t',2875});a.pb({'h',644});a.pb({'e',1343});a.pb({'m',2040});a.pb({'.',2735});a.pb({' ',496});a.pb({'O',1187});a.pb({'f',1876});a.pb({' ',2563});a.pb({'c',316});a.pb({'o',999});a.pb({'u',1680});a.pb({'r',2359});a.pb({'s',104});a.pb({'e',779});a.pb({',',1452});a.pb({' ',2123});a.pb({'c',2792});a.pb({'h',527});a.pb({'o',3047});a.pb({'s',2516});a.pb({'i',243});a.pb({'n',900});a.pb({'g',1555});a.pb({' ',2208});a.pb({'n',2859});a.pb({'e',576});a.pb({'v',1223});a.pb({'e',1868});a.pb({'r',2511});a.pb({' ',220});a.pb({'p',859});a.pb({'r',1496});a.pb({'e',2131});a.pb({'v',2764});a.pb({'i',463});a.pb({'o',1092});a.pb({'u',1719});a.pb({'s',2344});a.pb({'l',35});a.pb({'y',656});a.pb({' ',1275});a.pb({'c',1892});a.pb({'o',2507});a.pb({'n',188});a.pb({'s',799});a.pb({'u',1408});a.pb({'m',2015});a.pb({'e',2620});a.pb({'d',291});a.pb({' ',892});a.pb({'o',1491});a.pb({'r',2088});a.pb({' ',2683});a.pb({'d',344});a.pb({'e',935});a.pb({'s',1524});a.pb({'t',2111});a.pb({'r',2696});a.pb({'o',347});a.pb({'y',928});a.pb({'e',1507});a.pb({'d',2084});a.pb({'-',2659});a.pb({' ',300});a.pb({'w',871});a.pb({'a',1440});a.pb({'n',2007});a.pb({'e',2572});a.pb({'g',203});a.pb({'o',764});a.pb({' ',1323});a.pb({'s',1880});a.pb({'k',2435});a.pb({'y',56});a.pb({'s',607});a.pb({'c',1156});a.pb({'r',1703});a.pb({'a',2248});a.pb({'p',2791});a.pb({'e',400});a.pb({'r',939});a.pb({'.',1476});a.pb({' ',2011});a.pb({'W',2544});a.pb({'h',143});a.pb({'a',672});a.pb({'t',1199});a.pb({' ',1724});a.pb({'i',2247});a.pb({'s',2768});a.pb({' ',355});a.pb({'t',872});a.pb({'h',1387});a.pb({'e',1900});a.pb({' ',2411});a.pb({'m',2920});a.pb({'a',495});a.pb({'x',1000});a.pb({'i',1503});a.pb({'m',2004});a.pb({'u',2503});a.pb({'m',68});a.pb({' ',563});a.pb({'n',1056});a.pb({'u',1547});a.pb({'m',2036});a.pb({'b',2523});a.pb({'e',76});a.pb({'r',559});a.pb({' ',1040});a.pb({'o',1519});a.pb({'f',1996});a.pb({' ',2471});a.pb({'p',12});a.pb({'e',483});a.pb({'o',952});a.pb({'p',1419});a.pb({'l',1884});a.pb({'e',2347});a.pb({' ',2808});a.pb({'w',335});a.pb({'h',792});a.pb({'o',1247});a.pb({' ',1700});a.pb({'c',2151});a.pb({'a',2600});a.pb({'n',115});a.pb({' ',560});a.pb({'e',1003});a.pb({'a',1444});a.pb({'t',1883});a.pb({' ',2320});a.pb({'b',2755});a.pb({'e',256});a.pb({'f',687});a.pb({'o',1116});a.pb({'r',1543});a.pb({'e',1968});a.pb({' ',2391});a.pb({'t',2812});a.pb({'h',299});a.pb({'e',716});a.pb({' ',1131});a.pb({'c',1544});a.pb({'i',1955});a.pb({'t',2364});a.pb({'y',2771});a.pb({' ',244});a.pb({'c',647});a.pb({'o',1048});a.pb({'m',1447});a.pb({'p',1844});a.pb({'l',2239});a.pb({'e',2632});a.pb({'t',91});a.pb({'e',480});a.pb({'l',867});a.pb({'y',1252});a.pb({' ',1635});a.pb({'d',2016});a.pb({'e',2395});a.pb({'s',2772});a.pb({'o',215});a.pb({'l',588});a.pb({'a',959});a.pb({'t',1328});a.pb({'e',1695});a.pb({'?',2060});a.pb({' ',2423});a.pb({'E',2784});a.pb({'n',211});a.pb({'t',568});a.pb({'r',923});a.pb({'a',1276});a.pb({'n',1627});a.pb({'c',1976});a.pb({'e',2323});a.pb({' ',2668});a.pb({'T',79});a.pb({'h',420});a.pb({'e',759});a.pb({' ',1096});a.pb({'f',1431});a.pb({'i',1764});a.pb({'r',2095});a.pb({'s',2424});a.pb({'t',2751});a.pb({' ',144});a.pb({'l',467});a.pb({'i',788});a.pb({'n',1107});a.pb({'e',1424});a.pb({' ',1739});a.pb({'o',2052});a.pb({'f',2363});a.pb({' ',2672});a.pb({'s',47});a.pb({'t',352});a.pb({'a',655});a.pb({'n',956});a.pb({'d',1255});a.pb({'a',1552});a.pb({'r',1847});a.pb({'d',2140});a.pb({' ',2431});a.pb({'i',2720});a.pb({'n',75});a.pb({'p',360});a.pb({'u',643});a.pb({'t',924});a.pb({' ',1203});a.pb({'c',1480});a.pb({'o',1755});a.pb({'n',2028});a.pb({'t',2299});a.pb({'a',2568});a.pb({'i',2835});a.pb({'n',168});a.pb({'s',431});a.pb({' ',692});a.pb({'t',951});a.pb({'w',1208});a.pb({'o',1463});a.pb({' ',1716});a.pb({'i',1967});a.pb({'n',2216});a.pb({'t',2463});a.pb({'e',2708});a.pb({'g',19});a.pb({'e',260});a.pb({'r',499});a.pb({'s',736});a.pb({' ',971});a.pb({'h',1204});a.pb({'i',1435});a.pb({'m',1664});a.pb({' ',1891});a.pb({'(',2116});a.pb({'1',2339});a.pb({' ',2560});a.pb({'n',2779});a.pb({' ',64});a.pb({'1',279});a.pb({'0',1195});a.pb({' ',912});a.pb({'0',3970});a.pb({',',1728});a.pb({' ',1927});a.pb({'0',2124});a.pb({' ',2319});a.pb({'5',2512});a.pb({'0',5595});a.pb({' ',147});a.pb({'0',1543});a.pb({' ',875});a.pb({'m',1052});a.pb({')',1227});a.pb({' ',1400});a.pb({'r',1571});a.pb({'e',1740});a.pb({'s',1907});a.pb({'p',2072});a.pb({'e',2235});a.pb({'c',2396});a.pb({'t',2555});a.pb({'i',2712});a.pb({'v',2867});a.pb({'e',88});a.pb({'l',239});a.pb({'y',388});a.pb({' ',535});a.pb({'d',680});a.pb({'e',823});a.pb({'n',964});a.pb({'o',1103});a.pb({'t',1240});a.pb({'i',1375});a.pb({'n',1508});a.pb({'g',1639});a.pb({' ',1768});a.pb({'t',1895});a.pb({'h',2020});a.pb({'e',2143});a.pb({' ',2264});a.pb({'n',2383});a.pb({'u',2500});a.pb({'m',2615});a.pb({'b',2728});a.pb({'e',2839});a.pb({'r',16});a.pb({' ',123});a.pb({'o',228});a.pb({'f',331});a.pb({' ',432});a.pb({'i',531});a.pb({'n',628});a.pb({'t',723});a.pb({'e',816});a.pb({'r',907});a.pb({'s',996});a.pb({'e',1083});a.pb({'c',1168});a.pb({'t',1251});a.pb({'i',1332});a.pb({'o',1411});a.pb({'n',1488});a.pb({'s',1563});a.pb({' ',1636});a.pb({'i',1707});a.pb({'n',1776});a.pb({' ',1843});a.pb({'t',1908});a.pb({'h',1971});a.pb({'e',2032});a.pb({' ',2091});a.pb({'c',2148});a.pb({'i',2203});a.pb({'t',2256});a.pb({'y',2307});a.pb({' ',2356});a.pb({'a',2403});a.pb({'n',2448});a.pb({'d',2491});a.pb({' ',2532});a.pb({'t',2571});a.pb({'h',2608});a.pb({'e',2643});a.pb({' ',2676});a.pb({'n',2707});a.pb({'u',2736});a.pb({'m',2763});a.pb({'b',2788});a.pb({'e',2811});a.pb({'r',2832});a.pb({' ',2851});a.pb({'o',2868});a.pb({'f',2883});a.pb({' ',2896});a.pb({'c',2907});a.pb({'o',2916});a.pb({'n',5851});a.pb({'e',2931});a.pb({'c',2932});a.pb({'t',2931});a.pb({'i',2928});a.pb({'n',2923});a.pb({'g',2916});a.pb({' ',2907});a.pb({'s',2896});a.pb({'t',2883});a.pb({'r',2868});a.pb({'e',5683});a.pb({'t',2811});a.pb({'s',2788});a.pb({'.',2763});a.pb({' ',2736});a.pb({'C',2707});a.pb({'r',2676});a.pb({'o',2643});a.pb({'s',5179});a.pb({'r',2532});a.pb({'o',2491});a.pb({'a',2448});a.pb({'d',2403});a.pb({'s',2356});a.pb({' ',2307});a.pb({'n',2256});a.pb({'u',2203});a.pb({'m',2148});a.pb({'b',2091});a.pb({'e',2032});a.pb({'r',1971});a.pb({'s',1908});a.pb({' ',1843});a.pb({'a',1776});a.pb({'r',1707});a.pb({'e',1636});a.pb({' ',1563});a.pb({'n',1488});a.pb({'u',1411});a.pb({'m',1332});a.pb({'b',1251});a.pb({'e',1168});a.pb({'r',1083});a.pb({'e',996});a.pb({'d',907});a.pb({' ',816});a.pb({'f',723});a.pb({'r',628});a.pb({'o',531});a.pb({'m',432});a.pb({' ',331});a.pb({'1',228});a.pb({' ',123});a.pb({'t',16});a.pb({'o',2839});a.pb({' ',2728});a.pb({'n',2615});a.pb({',',2500});a.pb({' ',2383});a.pb({'j',2264});a.pb({'u',2143});a.pb({'n',2020});a.pb({'c',1895});a.pb({'t',1768});a.pb({'i',1639});a.pb({'o',1508});a.pb({'n',1375});a.pb({' ',1240});a.pb({'1',1103});a.pb({' ',964});a.pb({'i',823});a.pb({'s',680});a.pb({' ',535});a.pb({'l',388});a.pb({'o',239});a.pb({'c',88});a.pb({'a',2867});a.pb({'t',2712});a.pb({'e',2555});a.pb({'d',2396});a.pb({' ',2235});a.pb({'o',2072});a.pb({'n',1907});a.pb({' ',1740});a.pb({'t',1571});a.pb({'h',1400});a.pb({'e',1227});a.pb({' ',1052});a.pb({'s',875});a.pb({'h',696});a.pb({'o',515});a.pb({'r',332});a.pb({'e',147});a.pb({'s',2892});a.pb({' ',2703});a.pb({'o',2512});a.pb({'f',2319});a.pb({' ',2124});a.pb({'t',1927});a.pb({'h',1728});a.pb({'e',1527});a.pb({' ',1324});a.pb({'o',1119});a.pb({'c',912});a.pb({'e',703});a.pb({'a',492});a.pb({'n',279});a.pb({'.',64});a.pb({' ',2779});a.pb({'N',2560});a.pb({'e',2339});a.pb({'x',2116});a.pb({'t',1891});a.pb({' ',1664});a.pb({'r',1435});a.pb({'o',1204});a.pb({'w',971});a.pb({' ',736});a.pb({'c',499});a.pb({'o',260});a.pb({'n',19});a.pb({'t',2708});a.pb({'a',2463});a.pb({'i',2216});a.pb({'n',1967});a.pb({'s',1716});a.pb({' ',1463});a.pb({'a',1208});a.pb({' ',951});a.pb({'s',692});a.pb({'e',431});a.pb({'q',168});a.pb({'u',2835});a.pb({'e',2568});a.pb({'n',2299});a.pb({'c',2028});a.pb({'e',1755});a.pb({' ',1480});a.pb({'o',1203});a.pb({'f',924});a.pb({' ',643});a.pb({'i',360});a.pb({'n',75});a.pb({'t',2720});a.pb({'e',2431});a.pb({'g',2140});a.pb({'e',1847});a.pb({'r',1552});a.pb({'s',1255});a.pb({' ',956});a.pb({'n',655});a.pb({' ',352});a.pb({'s',47});a.pb({' ',2672});a.pb({'(',2363});a.pb({'0',2052});a.pb({' ',1739});a.pb({'s',1424});a.pb({' ',1107});a.pb({'1',788});a.pb({'0',611});a.pb({' ',2751});a.pb({'0',6283});a.pb({')',1431});a.pb({' ',1096});a.pb({'t',759});a.pb({'o',420});a.pb({' ',79});a.pb({'d',2668});a.pb({'e',2323});a.pb({'s',1976});a.pb({'c',1627});a.pb({'r',1276});a.pb({'i',923});a.pb({'b',568});a.pb({'e',211});a.pb({' ',2784});a.pb({'p',2423});a.pb({'o',2060});a.pb({'p',1695});a.pb({'u',1328});a.pb({'l',959});a.pb({'a',588});a.pb({'t',215});a.pb({'i',2772});a.pb({'o',2395});a.pb({'n',2016});a.pb({' ',1635});a.pb({'s',1252});a.pb({'k',867});a.pb({'y',480});a.pb({'s',91});a.pb({'c',2632});a.pb({'r',2239});a.pb({'a',1844});a.pb({'p',1447});a.pb({'e',1048});a.pb({'r',647});a.pb({'s',244});a.pb({' ',2771});a.pb({'a',2364});a.pb({'t',1955});a.pb({' ',1544});a.pb({'v',1131});a.pb({'a',716});a.pb({'r',299});a.pb({'i',2812});a.pb({'o',2391});a.pb({'u',1968});a.pb({'s',1543});a.pb({' ',1116});a.pb({'i',687});a.pb({'n',256});a.pb({'t',2755});a.pb({'e',2320});a.pb({'r',1883});a.pb({'s',1444});a.pb({'e',1003});a.pb({'c',560});a.pb({'t',115});a.pb({'i',2600});a.pb({'o',2151});a.pb({'n',1700});a.pb({'s',1247});a.pb({'.',792});a.pb({' ',335});a.pb({'I',2808});a.pb({'n',2347});a.pb({' ',1884});a.pb({'e',1419});a.pb({'a',952});a.pb({'c',483});a.pb({'h',12});a.pb({' ',2471});a.pb({'o',1996});a.pb({'f',1519});a.pb({' ',1040});a.pb({'t',559});a.pb({'h',76});a.pb({'e',2523});a.pb({' ',2036});a.pb({'n',1547});a.pb({'e',1056});a.pb({'x',563});a.pb({'t',68});a.pb({' ',2503});a.pb({'m',2004});a.pb({' ',1503});a.pb({'r',1000});a.pb({'o',495});a.pb({'w',2920});a.pb({'s',2411});a.pb({' ',1900});a.pb({'a',1387});a.pb({'r',872});a.pb({'e',355});a.pb({' ',2768});a.pb({'t',2247});a.pb({'h',1724});a.pb({'e',1199});a.pb({' ',672});a.pb({'t',143});a.pb({'w',2544});a.pb({'o',2011});a.pb({' ',1476});a.pb({'i',939});a.pb({'n',400});a.pb({'t',2791});a.pb({'e',2248});a.pb({'g',1703});a.pb({'e',1156});a.pb({'r',607});a.pb({'s',56});a.pb({' ',2435});a.pb({'a',1880});a.pb({'i',1323});a.pb({' ',764});a.pb({'a',203});a.pb({'n',2572});a.pb({'d',2007});a.pb({' ',1440});a.pb({'b',871});a.pb({'i',300});a.pb({' ',2659});a.pb({'(',2084});a.pb({'1',1507});a.pb({' ',928});a.pb({'a',347});a.pb({'i',2696});a.pb({',',2111});a.pb({' ',1524});a.pb({'b',935});a.pb({'i',344});a.pb({' ',2683});a.pb({'n',2088});a.pb({',',1491});a.pb({' ',892});a.pb({'a',291});a.pb({'i',2620});a.pb({' ',2015});a.pb({'=',1408});a.pb({' ',799});a.pb({'b',188});a.pb({'i',2507});a.pb({')',1892});a.pb({',',1275});a.pb({' ',656});a.pb({'w',35});a.pb({'h',2344});a.pb({'i',1719});a.pb({'c',1092});a.pb({'h',463});a.pb({' ',2764});a.pb({'m',2131});a.pb({'e',1496});a.pb({'a',859});a.pb({'n',220});a.pb({'s',2511});a.pb({' ',1868});a.pb({'t',1223});a.pb({'h',576});a.pb({'a',2859});a.pb({'t',2208});a.pb({' ',1555});a.pb({'t',900});a.pb({'h',243});a.pb({'e',2516});a.pb({'r',1855});a.pb({'e',1192});a.pb({' ',527});a.pb({'i',2792});a.pb({'s',2123});a.pb({' ',1452});a.pb({'a',779});a.pb({' ',104});a.pb({'r',2359});a.pb({'o',1680});a.pb({'a',999});a.pb({'d',316});a.pb({' ',2563});a.pb({'j',1876});a.pb({'u',1187});a.pb({'n',496});a.pb({'c',2735});a.pb({'t',2040});a.pb({'i',1343});a.pb({'o',644});a.pb({'n',2875});a.pb({' ',2172});a.pb({'c',1467});a.pb({'o',760});a.pb({'n',2323});a.pb({'e',1559});a.pb({'c',844});a.pb({'t',127});a.pb({'i',2340});a.pb({'n',1619});a.pb({'g',896});a.pb({' ',171});a.pb({'a',2376});a.pb({'i',1647});a.pb({' ',916});a.pb({'a',183});a.pb({'n',2380});a.pb({'d',1643});a.pb({' ',904});a.pb({'b',163});a.pb({'i',2352});a.pb({'.',1607});a.pb({' ',860});a.pb({'T',111});a.pb({'h',2292});a.pb({'e',1539});a.pb({' ',784});a.pb({'c',27});a.pb({'r',2200});a.pb({'o',1439});a.pb({'s',3519});a.pb({'i',2076});a.pb({'n',1307});a.pb({'g',536});a.pb({' ',2695});a.pb({'n',1920});a.pb({'u',1143});a.pb({'m',364});a.pb({'b',2515});a.pb({'e',1732});a.pb({'r',947});a.pb({' ',160});a.pb({'O',2303});a.pb({'n',1512});a.pb({'e',719});a.pb({' ',2856});a.pb({'c',2059});a.pb({'a',1260});a.pb({'n',459});a.pb({' ',2588});a.pb({'r',1783});a.pb({'e',976});a.pb({'a',167});a.pb({'c',2288});a.pb({'h',1475});a.pb({' ',660});a.pb({'a',2775});a.pb({'n',1956});a.pb({'y',1135});a.pb({' ',312});a.pb({'o',2419});a.pb({'t',1592});a.pb({'h',763});a.pb({'e',2864});a.pb({'r',2031});a.pb({' ',1196});a.pb({'i',359});a.pb({'n',2452});a.pb({'t',1611});a.pb({'e',768});a.pb({'r',2855});a.pb({'s',2008});a.pb({'e',1159});a.pb({'c',308});a.pb({'t',2387});a.pb({'i',1532});a.pb({'o',675});a.pb({'n',2748});a.pb({' ',1887});a.pb({'i',1024});a.pb({'n',159});a.pb({' ',2224});a.pb({'t',1355});a.pb({'h',484});a.pb({'e',2543});a.pb({' ',1668});a.pb({'c',791});a.pb({'i',2844});a.pb({'t',1963});a.pb({'y',1080});a.pb({'.',195});a.pb({' ',2240});a.pb({'E',1351});a.pb({'x',460});a.pb({'i',2499});a.pb({'t',1604});a.pb({' ',707});a.pb({'W',2740});a.pb({'r',1839});a.pb({'i',936});a.pb({'t',31});a.pb({'e',2056});a.pb({' ',1147});a.pb({'t',236});a.pb({'o',2255});a.pb({' ',1340});a.pb({'s',423});a.pb({'t',2436});a.pb({'d',1515});a.pb({'o',592});a.pb({'u',2599});a.pb({'t',1672});a.pb({' ',743});a.pb({'t',2744});a.pb({'h',1811});a.pb({'e',876});a.pb({' ',2871});a.pb({'n',1932});a.pb({'u',991});a.pb({'m',48});a.pb({'b',2035});a.pb({'e',1088});a.pb({'r',139});a.pb({' ',2120});a.pb({'o',1167});a.pb({'f',212});a.pb({' ',2187});a.pb({'p',1228});a.pb({'e',267});a.pb({'o',2236});a.pb({'p',1271});a.pb({'l',304});a.pb({'e',2267});a.pb({' ',1296});a.pb({'w',323});a.pb({'h',2280});a.pb({'o',1303});a.pb({' ',324});a.pb({'e',2275});a.pb({'a',1292});a.pb({'t',307});a.pb({' ',2252});a.pb({'G',1263});a.pb({'o',272});a.pb({'d',2211});a.pb({'z',1216});a.pb({'i',219});a.pb({'l',3303});a.pb({'a',148});a.pb({' ',2075});a.pb({'f',1068});a.pb({'o',59});a.pb({'r',1980});a.pb({' ',967});a.pb({'t',2884});a.pb({'h',1867});a.pb({'e',848});a.pb({' ',2759});a.pb({'o',1736});a.pb({'p',711});a.pb({'t',2616});a.pb({'i',1587});a.pb({'m',556});a.pb({'u',2455});a.pb({'m',1420});a.pb({' ',383});a.pb({'c',2276});a.pb({'h',1235});a.pb({'o',192});a.pb({'i',2079});a.pb({'c',1032});a.pb({'e',2915});a.pb({' ',1864});a.pb({'o',811});a.pb({'f',2688});a.pb({' ',1631});a.pb({'m',572});a.pb({'e',2443});a.pb({'a',1380});a.pb({'l',315});a.pb({'s',2180});a.pb({' ',1111});a.pb({'a',40});a.pb({'n',1899});a.pb({'d',824});a.pb({' ',2679});a.pb({'r',1600});a.pb({'o',519});a.pb({'a',2368});a.pb({'d',1283});a.pb({'s',196});a.pb({' ',2039});a.pb({'t',948});a.pb({'h',2787});a.pb({'r',1692});a.pb({'o',595});a.pb({'u',2428});a.pb({'g',1327});a.pb({'h',224});a.pb({' ',2051});a.pb({'t',944});a.pb({'h',2767});a.pb({'e',1656});a.pb({' ',543});a.pb({'c',2360});a.pb({'i',1243});a.pb({'t',124});a.pb({'y',1935});a.pb({' ',812});a.pb({'e',2619});a.pb({'v',1492});a.pb({'e',363});a.pb({'r',2164});a.pb({'y',1031});a.pb({' ',2828});a.pb({'d',1691});a.pb({'a',552});a.pb({'y',2343});a.pb({'.',1200});a.pb({' ',55});a.pb({'E',1840});a.pb({'x',691});a.pb({'a',2472});a.pb({'m',1319});a.pb({'p',164});a.pb({'l',1939});a.pb({'e',780});a.pb({' ',2551});a.pb({'F',1388});a.pb({'o',223});a.pb({'r',1988});a.pb({' ',819});a.pb({'i',2580});a.pb({'n',1407});a.pb({'p',232});a.pb({'u',1987});a.pb({'t',808});a.pb({':',2559});a.pb({' ',1376});a.pb({'t',191});a.pb({'h',1936});a.pb({'e',747});a.pb({' ',2488});a.pb({'r',1295});a.pb({'e',100});a.pb({'s',1835});a.pb({'u',636});a.pb({'l',2367});a.pb({'t',1164});a.pb({' ',2891});a.pb({'i',1684});a.pb({'s',475});a.pb({' ',2196});a.pb({'c',983});a.pb({'o',2700});a.pb({'r',1747});a.pb({'e',1975});a.pb({'c',752});a.pb({'t',2459});a.pb({':',1232});a.pb({' ',3});a.pb({'5',1704});a.pb({' ',471});a.pb({'5',2168});a.pb({' ',931});a.pb({'1',4007});a.pb({' ',140});a.pb({'1',1827});a.pb({' ',580});a.pb({'3',2263});a.pb({' ',1012});a.pb({'2',2691});a.pb({' ',1436});a.pb({'4',179});a.pb({' ',1852});a.pb({'7',591});a.pb({' ',2260});a.pb({'1',995});a.pb({' ',2660});a.pb({'2',1391});a.pb({' ',120});a.pb({'1',1779});a.pb({' ',504});a.pb({'3',2159});a.pb({' ',880});a.pb({'2',2531});a.pb({' ',1248});a.pb({'3',2895});a.pb({' ',1608});a.pb({'2',319});a.pb({' ',1960});a.pb({'4',667});a.pb({' ',2304});a.pb({'3',1007});a.pb({' ',2640});a.pb({'5',1339});
        for(auto v:a){
            for(int i=0; i<v.second; i++){
                cout<<v.first;
            }
        }
    }
    if(n==2){
        vector<ll>dp(10101);
        dp[0]=dp[1]=1;
        ll mod=9099099909999099999;
        for(int i=2; i<10000; i++){
            dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
        }
        for(int i=0; i<10000; i++)cout<<dp[i]<<", ";
        cout<<"0.";
    }
    if(n==3){
        //507~511
        int c=0;
        for(int i=0; i<1024; i++){
            string s="";
            for(int j=0; j<1024-i; j++){
                if(i==506 and j==450){
                    cout<<s<<"####..##..##.######..##...##..##.....####...####..###..####...##..##";
                    c=1;
                    break;
                }

                s+=i&j?'.':'#';
            }
            cout<<(c?"":s)<<endl;
        }
    }
    if(n==4){
        int arr[40001];
        for(int i=2; i<=50000; i++)arr[i]=i;
        for(int i=2; i<=50000; i++){
            if(arr[i]==0)continue;
            for(int j=2*i; j<=50000; j+=i)arr[j]=0;
        }
        for(int i=2; i<=40000; i++){
            
        }
    }
    return 0;
}