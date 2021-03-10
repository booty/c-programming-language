/*
Had to hard code in a semi-large array and perform 50m
reps so that execution would take a meaningful amount of time.

$ time ./a.out
./a.out  9.37s user 0.01s system 99% cpu 9.398 total
*/

#include <stdio.h>
#include <stdlib.h>

#define NUMREPS 50000000

int binsearch(int target, int v[], int num_elements) {
	int low_pos, high_pos, mid_pos;

	low_pos = 0;

	high_pos = num_elements - 1;

	while (low_pos <= high_pos) {
		mid_pos = (low_pos+high_pos) / 2;

		if (target < v[mid_pos])
			high_pos = mid_pos - 1;
		else if (target > v[mid_pos])
			low_pos = mid_pos + 1;
		else
			return mid_pos;
	}

	return -1;  // no match

}

int main() {
	int result;
	int values[] = {
		4, 8, 8, 8, 11, 13, 15, 20, 22, 23, 23, 27, 32, 36, 37, 38, 43, 48, 48, 52,
		54, 54, 55, 58, 59, 59, 60, 61, 61, 66, 67, 71, 74, 77, 79, 81, 86, 88, 93,
		94, 95, 98, 98, 98, 98, 101, 105, 110, 113, 113, 113, 114, 114, 116, 117,
		121, 121, 122, 126, 128, 128, 130, 130, 131, 132, 136, 141, 144, 148, 148,
		150, 151, 154, 159, 161, 166, 167, 168, 172, 173, 176, 178, 182, 184, 187,
		188, 189, 190, 191, 194, 198, 203, 205, 207, 212, 212, 215, 220, 222, 222,
		226, 226, 231, 232, 235, 240, 245, 248, 250, 255, 259, 259, 263, 265, 268,
		273, 273, 275, 276, 280, 280, 282, 285, 289, 293, 294, 296, 297, 299, 303,
		304, 307, 309, 312, 312, 312, 315, 315, 317, 322, 322, 322, 327, 327, 328,
		329, 331, 336, 339, 340, 343, 347, 349, 353, 356, 359, 360, 362, 365, 369,
		371, 372, 376, 377, 379, 382, 384, 389, 394, 399, 400, 405, 406, 409, 412,
		413, 417, 422, 423, 423, 424, 427, 429, 431, 432, 436, 438, 443, 444, 449,
		453, 458, 462, 463, 464, 466, 469, 472, 476, 479, 479, 481, 486, 488, 493,
		497, 502, 505, 506, 511, 511, 511, 511, 514, 515, 518, 521, 526, 526, 530,
		533, 535, 536, 538, 539, 540, 542, 543, 548, 549, 553, 556, 556, 561, 563,
		564, 568, 572, 575, 580, 581, 585, 585, 588, 593, 597, 598, 600, 600, 602,
		606, 606, 608, 613, 618, 620, 625, 625, 630, 632, 636, 641, 642, 642, 646,
		647, 651, 653, 658, 661, 666, 671, 673, 678, 681, 683, 688, 689, 691, 693,
		695, 697, 698, 698, 703, 704, 704, 705, 707, 709, 709, 711, 712, 716, 718,
		722, 727, 727, 729, 732, 733, 733, 738, 739, 744, 749, 752, 757, 759, 764,
		769, 774, 778, 778, 783, 784, 789, 790, 794, 794, 795, 795, 795, 795, 797,
		800, 802, 806, 807, 812, 815, 816, 817, 822, 827, 827, 829, 833, 833, 837,
		841, 842, 843, 843, 843, 844, 844, 844, 844, 849, 850, 851, 852, 856, 859,
		860, 860, 863, 865, 865, 866, 866, 866, 867, 869, 870, 870, 873, 875, 875,
		880, 881, 884, 885, 888, 890, 895, 896, 900, 902, 902, 905, 905, 909, 910,
		914, 919, 922, 922, 922, 927, 929, 929, 933, 938, 939, 939, 944, 946, 947,
		952, 955, 957, 962, 962, 967, 967, 967, 971, 971, 974, 979, 982, 982, 984,
		989, 990, 995, 997, 1000, 1004, 1006, 1010, 1015, 1015, 1018, 1021, 1026,
		1029, 1034, 1034, 1038, 1040, 1045, 1048, 1052, 1055, 1055, 1060, 1063,
		1063, 1063, 1068, 1070, 1075, 1080, 1085, 1090, 1095, 1095, 1095, 1100,
		1104, 1104, 1109, 1112, 1117, 1117, 1120, 1122, 1123, 1123, 1128, 1130,
		1132, 1134, 1134, 1136, 1140, 1141, 1142, 1147, 1151, 1153, 1157, 1158,
		1159, 1162, 1164, 1169, 1171, 1176, 1176, 1176, 1177, 1179, 1182, 1185,
		1186, 1190, 1193, 1193, 1198, 1200, 1205, 1208, 1211, 1214, 1218, 1223,
		1224, 1229, 1234, 1236, 1238, 1243, 1245, 1245, 1250, 1250, 1254, 1257,
		1260, 1261, 1264, 1266, 1271, 1272, 1276, 1277, 1280, 1283, 1285, 1285,
		1290, 1291, 1296, 1300, 1301, 1306, 1309, 1313, 1316, 1320, 1324, 1326,
		1328, 1328, 1332, 1336, 1336, 1337, 1341, 1343, 1348, 1348, 1352, 1353,
		1356, 1359, 1363, 1365, 1368, 1372, 1376, 1381, 1382, 1382, 1383, 1387,
		1389, 1390, 1394, 1399, 1400, 1405, 1407, 1412, 1414, 1414, 1415, 1417,
		1418, 1419, 1422, 1423, 1427, 1427, 1428, 1433, 1434, 1436, 1438, 1440,
		1440, 1444, 1447, 1449, 1454, 1454, 1457, 1458, 1462, 1462, 1464, 1466,
		1466, 1471, 1473, 1474, 1479, 1481, 1483, 1488, 1489, 1494, 1497, 1497,
		1501, 1503, 1508, 1511, 1515, 1515, 1517, 1519, 1523, 1524, 1527, 1531,
		1536, 1536, 1537, 1537, 1538, 1539, 1541, 1542, 1547, 1549, 1550, 1551,
		1554, 1554, 1559, 1564, 1567, 1572, 1575, 1580, 1581, 1585, 1586, 1591,
		1592, 1593, 1593, 1595, 1595, 1597, 1599, 1602, 1606, 1610, 1614, 1617,
		1617, 1621, 1621, 1621, 1622, 1622, 1624, 1629, 1634, 1638, 1640, 1644,
		1648, 1648, 1648, 1652, 1656, 1660, 1662, 1666, 1668, 1670, 1674, 1677,
		1677, 1682, 1685, 1690, 1690, 1691, 1694, 1696, 1697, 1702, 1705, 1708,
		1709, 1710, 1713, 1718, 1723, 1728, 1730, 1731, 1736, 1739, 1742, 1747,
		1747, 1752, 1753, 1755, 1758, 1758, 1760, 1762, 1767, 1767, 1767, 1768,
		1768, 1772, 1774, 1777, 1777, 1779, 1784, 1785, 1790, 1794, 1794, 1794,
		1798, 1803, 1806, 1810, 1811, 1814, 1815, 1815, 1820, 1823, 1827, 1827,
		1827, 1830, 1834, 1837, 1840, 1844, 1847, 1851, 1852, 1854, 1856, 1856,
		1856, 1861, 1861, 1863, 1866, 1868, 1871, 1871, 1871, 1876, 1881, 1883,
		1885, 1885, 1885, 1889, 1891, 1893, 1894, 1898, 1901, 1903, 1907, 1907,
		1908, 1909, 1912, 1912, 1916, 1918, 1919, 1923, 1923, 1926, 1931, 1932,
		1932, 1933, 1936, 1940, 1940, 1944, 1944, 1946, 1946, 1948, 1952, 1954,
		1959, 1964, 1969, 1971, 1975, 1976, 1980, 1984, 1984, 1984, 1985, 1989,
		1990, 1992, 1997, 1998, 1998, 2001, 2002, 2004, 2008, 2011, 2013, 2017,
		2019, 2020, 2023, 2024, 2025, 2026, 2026, 2027, 2027, 2032, 2032, 2035,
		2035, 2037, 2041, 2043, 2046, 2049, 2049, 2051, 2056, 2059, 2061, 2064,
		2066, 2066, 2067, 2067, 2070, 2074, 2078, 2083, 2084, 2084, 2084, 2084,
		2089, 2091, 2096, 2096, 2100, 2101, 2103, 2103, 2103, 2105, 2105, 2108,
		2108, 2110, 2115, 2118, 2123, 2126, 2127, 2132, 2133, 2137, 2142, 2145,
		2147, 2150, 2153, 2157, 2158, 2163, 2168, 2171, 2171, 2171, 2176, 2177,
		2182, 2182, 2184, 2187, 2191, 2196, 2200, 2202, 2202, 2204, 2206, 2209,
		2212, 2214, 2218, 2222, 2226, 2226, 2227, 2227, 2227, 2227, 2227, 2229,
		2229, 2232, 2235, 2239, 2239, 2241, 2246, 2249, 2253, 2255, 2260, 2261,
		2261, 2263, 2266, 2268, 2269, 2269, 2271, 2272, 2277, 2278, 2278, 2279,
		2283, 2285, 2288, 2288, 2293, 2295, 2300, 2304, 2306, 2307, 2311, 2315,
		2315, 2320, 2323, 2325, 2330, 2334, 2338, 2338, 2339, 2342, 2345, 2345,
		2347, 2351, 2354, 2357, 2362, 2364, 2365, 2368, 2369, 2373, 2374, 2375,
		2378, 2380, 2383, 2388, 2388, 2390, 2393, 2395, 2400, 2402, 2406, 2406,
		2407, 2412, 2414, 2417, 2420, 2422, 2427, 2429, 2430, 2435, 2435, 2438,
		2440, 2440, 2444, 2447, 2447, 2448, 2451, 2453, 2458, 2458, 2463, 2466,
		2468, 2468, 2470, 2473, 2478, 2479, 2481, 2485, 2489, 2494, 2494, 2495,
		2498, 2500, 2502, 2507, 2512, 2515, 2517, 2519, 2523, 2527, 2529, 2534,
		2534, 2534, 2538, 2538, 2538, 2539, 2541, 2543, 2544, 2548, 2551, 2551,
		2553, 2556, 2559, 2561, 2564, 2568, 2571, 2571, 2572, 2572, 2576, 2576,
		2577, 2577, 2582, 2586, 2590, 2590, 2595, 2598, 2602, 2604, 2608, 2609,
		2612, 2617, 2619, 2619, 2619, 2622, 2622, 2625, 2627, 2629, 2634, 2637,
		2640, 2643, 2648, 2651, 2654, 2654, 2657, 2661, 2664, 2669, 2673, 2677,
		2678, 2679, 2682, 2686, 2687, 2691, 2694, 2698, 2700, 2703, 2706, 2709,
		2714, 2714, 2715, 2716, 2718, 2718, 2719, 2723, 2724, 2724, 2726, 2731,
		2733, 2736, 2740, 2743, 2743, 2744, 2749, 2749, 2752, 2757, 2759, 2762,
		2766, 2770, 2770, 2773, 2775, 2779, 2782, 2782, 2782, 2786, 2790, 2793,
		2796, 2796, 2796, 2796, 2796, 2800, 2804, 2805, 2810, 2813, 2816, 2817,
		2822, 2826, 2830, 2832, 2835, 2836, 2839, 2841, 2846, 2850, 2850, 2853,
		2856, 2859, 2860, 2860, 2865, 2865, 2867, 2869, 2874, 2878, 2879, 2881,
		2885, 2889, 2890, 2890, 2895, 2895, 2898, 2898, 2898, 2900, 2902, 2907,
		2910, 2910, 2914, 2914, 2916, 2918, 2922, 2926, 2929, 2931, 2933, 2934,
		2934, 2939, 2940, 2942, 2943, 2945, 2945, 2949, 2952, 2953, 2953, 2953,
		2955, 2960, 2960, 2962, 2962, 2967, 2970, 2973, 2975, 2979, 2980, 2984,
		2986, 2989, 2994, 2997, 2997, 3002, 3002, 3004, 3006, 3006, 3010, 3011,
		3013, 3018, 3019, 3022, 3027, 3032, 3035, 3039, 3041, 3041, 3046, 3051,
		3053, 3057, 3058, 3062, 3064, 3068, 3073, 3077, 3079, 3084, 3084, 3085,
		3088, 3091, 3096, 3096, 3098, 3098, 3099, 3104, 3107, 3111, 3111, 3116,
		3117, 3117, 3121, 3123, 3123, 3128, 3130, 3132, 3133, 3134, 3139, 3141,
		3145, 3146, 3146, 3146, 3146, 3151, 3156, 3160, 3163, 3163, 3168, 3170,
		3174, 3176, 3178, 3181, 3181, 3185, 3188, 3192, 3195, 3195, 3198, 3202,
		3205, 3208, 3210, 3213, 3217, 3221, 3222, 3226, 3229, 3232, 3233, 3237,
		3238, 3241, 3243, 3244, 3247, 3248, 3253, 3256, 3256, 3257, 3258, 3263,
		3266, 3266, 3267, 3268, 3271, 3275, 3280, 3281, 3285, 3285, 3285, 3287,
		3289, 3293, 3295, 3300, 3305, 3307, 3308, 3313, 3316, 3316, 3318, 3319,
		3319, 3322, 3327, 3327, 3330, 3333, 3333, 3335, 3337, 3339, 3340, 3345,
		3347, 3347, 3349, 3354, 3357, 3361, 3365, 3367, 3370, 3374, 3375, 3378,
		3382, 3386, 3386, 3387, 3391, 3393, 3394, 3397, 3399, 3401, 3405, 3410,
		3411, 3415, 3415, 3419, 3421, 3424, 3429, 3433, 3436, 3436, 3440, 3443,
		3447, 3448, 3451, 3452, 3457, 3458, 3459, 3463, 3468, 3472, 3475, 3478,
		3482, 3482, 3486, 3490, 3495, 3499, 3501, 3504, 3507, 3512, 3514, 3514,
		3517, 3520, 3521, 3524, 3528, 3531, 3535, 3540, 3545, 3548, 3550, 3550,
		3553, 3558, 3563, 3563, 3566, 3568, 3573, 3574, 3578, 3580, 3580, 3583,
		3583, 3583, 3585, 3590, 3590, 3590, 3592, 3592, 3593, 3597, 3599, 3599,
		3604, 3606, 3608, 3612, 3612, 3617, 3620, 3623, 3628, 3630, 3633, 3633,
		3638, 3638, 3638, 3638, 3643, 3645, 3646, 3646, 3648, 3650, 3651, 3652,
		3653, 3657, 3662, 3663
	};
	int rep_number = 0;

	while (rep_number < NUMREPS) {
		result = binsearch(
			(rand() % 3600),
			values,
			1500
		);

		rep_number++;
	}

	printf("Result from last run: %d\n", result);
	return 0;
}