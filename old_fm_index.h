// #include <string.h>
#include <math.h>
#include <vector>
#include <stdint.h>

#define DEBUG 0
#define STEP 5

extern const uint32_t TOTAL_COMB_CNT = (uint32_t)((1 + (float)STEP / 4) * pow(4, STEP));
extern const uint32_t ALL_POSS_COMB_CNT = (uint32_t)pow(5, STEP);

#if STEP == 1
int EncodedArray[] = {0, 1, 2, 3, 4};
#endif
#if STEP == 2
int EncodedArray[] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
#endif

#if STEP == 3
int EncodedArray[] = {-1, -1, -1, -1, -1, -1, 0, 1, 2, 3, -1, 4, 5, 6, 7, -1, 8, 9, 10, 11, -1, 12, 13, 14, 15, -1, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, -1, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, -1, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, -1, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111};
#endif

#if STEP == 4
int EncodedArray[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 3, -1, 4, 5, 6, 7, -1, 8, 9, 10, 11, -1, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, 16, 17, 18, 19, -1, 20, 21, 22, 23, -1, 24, 25, 26, 27, -1, 28, 29, 30, 31, -1, -1, -1, -1, -1, -1, 32, 33, 34, 35, -1, 36, 37, 38, 39, -1, 40, 41, 42, 43, -1, 44, 45, 46, 47, -1, -1, -1, -1, -1, -1, 48, 49, 50, 51, -1, 52, 53, 54, 55, -1, 56, 57, 58, 59, -1, 60, 61, 62, 63, -1, -1, -1, -1, -1, -1, 64, 65, 66, 67, -1, 68, 69, 70, 71, -1, 72, 73, 74, 75, -1, 76, 77, 78, 79, -1, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, -1, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, -1, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, -1, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, -1, -1, -1, -1, -1, -1, 176, 177, 178, 179, -1, 180, 181, 182, 183, -1, 184, 185, 186, 187, -1, 188, 189, 190, 191, -1, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, -1, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, -1, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, -1, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, -1, -1, -1, -1, -1, -1, 288, 289, 290, 291, -1, 292, 293, 294, 295, -1, 296, 297, 298, 299, -1, 300, 301, 302, 303, -1, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, -1, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, -1, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, -1, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, -1, -1, -1, -1, -1, -1, 400, 401, 402, 403, -1, 404, 405, 406, 407, -1, 408, 409, 410, 411, -1, 412, 413, 414, 415, -1, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, -1, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, -1, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, -1, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511};
#endif

#if STEP == 5
int EncodedArray[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 3, -1, 4, 5, 6, 7, -1, 8, 9, 10, 11, -1, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, 16, 17, 18, 19, -1, 20, 21, 22, 23, -1, 24, 25, 26, 27, -1, 28, 29, 30, 31, -1, -1, -1, -1, -1, -1, 32, 33, 34, 35, -1, 36, 37, 38, 39, -1, 40, 41, 42, 43, -1, 44, 45, 46, 47, -1, -1, -1, -1, -1, -1, 48, 49, 50, 51, -1, 52, 53, 54, 55, -1, 56, 57, 58, 59, -1, 60, 61, 62, 63, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 64, 65, 66, 67, -1, 68, 69, 70, 71, -1, 72, 73, 74, 75, -1, 76, 77, 78, 79, -1, -1, -1, -1, -1, -1, 80, 81, 82, 83, -1, 84, 85, 86, 87, -1, 88, 89, 90, 91, -1, 92, 93, 94, 95, -1, -1, -1, -1, -1, -1, 96, 97, 98, 99, -1, 100, 101, 102, 103, -1, 104, 105, 106, 107, -1, 108, 109, 110, 111, -1, -1, -1, -1, -1, -1, 112, 113, 114, 115, -1, 116, 117, 118, 119, -1, 120, 121, 122, 123, -1, 124, 125, 126, 127, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 128, 129, 130, 131, -1, 132, 133, 134, 135, -1, 136, 137, 138, 139, -1, 140, 141, 142, 143, -1, -1, -1, -1, -1, -1, 144, 145, 146, 147, -1, 148, 149, 150, 151, -1, 152, 153, 154, 155, -1, 156, 157, 158, 159, -1, -1, -1, -1, -1, -1, 160, 161, 162, 163, -1, 164, 165, 166, 167, -1, 168, 169, 170, 171, -1, 172, 173, 174, 175, -1, -1, -1, -1, -1, -1, 176, 177, 178, 179, -1, 180, 181, 182, 183, -1, 184, 185, 186, 187, -1, 188, 189, 190, 191, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 192, 193, 194, 195, -1, 196, 197, 198, 199, -1, 200, 201, 202, 203, -1, 204, 205, 206, 207, -1, -1, -1, -1, -1, -1, 208, 209, 210, 211, -1, 212, 213, 214, 215, -1, 216, 217, 218, 219, -1, 220, 221, 222, 223, -1, -1, -1, -1, -1, -1, 224, 225, 226, 227, -1, 228, 229, 230, 231, -1, 232, 233, 234, 235, -1, 236, 237, 238, 239, -1, -1, -1, -1, -1, -1, 240, 241, 242, 243, -1, 244, 245, 246, 247, -1, 248, 249, 250, 251, -1, 252, 253, 254, 255, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 256, 257, 258, 259, -1, 260, 261, 262, 263, -1, 264, 265, 266, 267, -1, 268, 269, 270, 271, -1, -1, -1, -1, -1, -1, 272, 273, 274, 275, -1, 276, 277, 278, 279, -1, 280, 281, 282, 283, -1, 284, 285, 286, 287, -1, -1, -1, -1, -1, -1, 288, 289, 290, 291, -1, 292, 293, 294, 295, -1, 296, 297, 298, 299, -1, 300, 301, 302, 303, -1, -1, -1, -1, -1, -1, 304, 305, 306, 307, -1, 308, 309, 310, 311, -1, 312, 313, 314, 315, -1, 316, 317, 318, 319, -1, -1, -1, -1, -1, -1, 320, 321, 322, 323, -1, 324, 325, 326, 327, -1, 328, 329, 330, 331, -1, 332, 333, 334, 335, -1, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, -1, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, -1, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, -1, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, -1, -1, -1, -1, -1, -1, 432, 433, 434, 435, -1, 436, 437, 438, 439, -1, 440, 441, 442, 443, -1, 444, 445, 446, 447, -1, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, -1, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, -1, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 516, 517, 518, 519, -1, 520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, -1, -1, -1, -1, -1, -1, 544, 545, 546, 547, -1, 548, 549, 550, 551, -1, 552, 553, 554, 555, -1, 556, 557, 558, 559, -1, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582, 583, -1, 584, 585, 586, 587, 588, 589, 590, 591, 592, 593, 594, 595, 596, 597, 598, 599, 600, 601, 602, 603, 604, 605, 606, 607, -1, 608, 609, 610, 611, 612, 613, 614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626, 627, 628, 629, 630, 631, -1, 632, 633, 634, 635, 636, 637, 638, 639, 640, 641, 642, 643, 644, 645, 646, 647, 648, 649, 650, 651, 652, 653, 654, 655, -1, -1, -1, -1, -1, -1, 656, 657, 658, 659, -1, 660, 661, 662, 663, -1, 664, 665, 666, 667, -1, 668, 669, 670, 671, -1, 672, 673, 674, 675, 676, 677, 678, 679, 680, 681, 682, 683, 684, 685, 686, 687, 688, 689, 690, 691, 692, 693, 694, 695, -1, 696, 697, 698, 699, 700, 701, 702, 703, 704, 705, 706, 707, 708, 709, 710, 711, 712, 713, 714, 715, 716, 717, 718, 719, -1, 720, 721, 722, 723, 724, 725, 726, 727, 728, 729, 730, 731, 732, 733, 734, 735, 736, 737, 738, 739, 740, 741, 742, 743, -1, 744, 745, 746, 747, 748, 749, 750, 751, 752, 753, 754, 755, 756, 757, 758, 759, 760, 761, 762, 763, 764, 765, 766, 767, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 768, 769, 770, 771, -1, 772, 773, 774, 775, -1, 776, 777, 778, 779, -1, 780, 781, 782, 783, -1, -1, -1, -1, -1, -1, 784, 785, 786, 787, -1, 788, 789, 790, 791, -1, 792, 793, 794, 795, -1, 796, 797, 798, 799, -1, -1, -1, -1, -1, -1, 800, 801, 802, 803, -1, 804, 805, 806, 807, -1, 808, 809, 810, 811, -1, 812, 813, 814, 815, -1, -1, -1, -1, -1, -1, 816, 817, 818, 819, -1, 820, 821, 822, 823, -1, 824, 825, 826, 827, -1, 828, 829, 830, 831, -1, -1, -1, -1, -1, -1, 832, 833, 834, 835, -1, 836, 837, 838, 839, -1, 840, 841, 842, 843, -1, 844, 845, 846, 847, -1, 848, 849, 850, 851, 852, 853, 854, 855, 856, 857, 858, 859, 860, 861, 862, 863, 864, 865, 866, 867, 868, 869, 870, 871, -1, 872, 873, 874, 875, 876, 877, 878, 879, 880, 881, 882, 883, 884, 885, 886, 887, 888, 889, 890, 891, 892, 893, 894, 895, -1, 896, 897, 898, 899, 900, 901, 902, 903, 904, 905, 906, 907, 908, 909, 910, 911, 912, 913, 914, 915, 916, 917, 918, 919, -1, 920, 921, 922, 923, 924, 925, 926, 927, 928, 929, 930, 931, 932, 933, 934, 935, 936, 937, 938, 939, 940, 941, 942, 943, -1, -1, -1, -1, -1, -1, 944, 945, 946, 947, -1, 948, 949, 950, 951, -1, 952, 953, 954, 955, -1, 956, 957, 958, 959, -1, 960, 961, 962, 963, 964, 965, 966, 967, 968, 969, 970, 971, 972, 973, 974, 975, 976, 977, 978, 979, 980, 981, 982, 983, -1, 984, 985, 986, 987, 988, 989, 990, 991, 992, 993, 994, 995, 996, 997, 998, 999, 1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, -1, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020, 1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028, 1029, 1030, 1031, -1, 1032, 1033, 1034, 1035, 1036, 1037, 1038, 1039, 1040, 1041, 1042, 1043, 1044, 1045, 1046, 1047, 1048, 1049, 1050, 1051, 1052, 1053, 1054, 1055, -1, -1, -1, -1, -1, -1, 1056, 1057, 1058, 1059, -1, 1060, 1061, 1062, 1063, -1, 1064, 1065, 1066, 1067, -1, 1068, 1069, 1070, 1071, -1, 1072, 1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088, 1089, 1090, 1091, 1092, 1093, 1094, 1095, -1, 1096, 1097, 1098, 1099, 1100, 1101, 1102, 1103, 1104, 1105, 1106, 1107, 1108, 1109, 1110, 1111, 1112, 1113, 1114, 1115, 1116, 1117, 1118, 1119, -1, 1120, 1121, 1122, 1123, 1124, 1125, 1126, 1127, 1128, 1129, 1130, 1131, 1132, 1133, 1134, 1135, 1136, 1137, 1138, 1139, 1140, 1141, 1142, 1143, -1, 1144, 1145, 1146, 1147, 1148, 1149, 1150, 1151, 1152, 1153, 1154, 1155, 1156, 1157, 1158, 1159, 1160, 1161, 1162, 1163, 1164, 1165, 1166, 1167, -1, -1, -1, -1, -1, -1, 1168, 1169, 1170, 1171, -1, 1172, 1173, 1174, 1175, -1, 1176, 1177, 1178, 1179, -1, 1180, 1181, 1182, 1183, -1, 1184, 1185, 1186, 1187, 1188, 1189, 1190, 1191, 1192, 1193, 1194, 1195, 1196, 1197, 1198, 1199, 1200, 1201, 1202, 1203, 1204, 1205, 1206, 1207, -1, 1208, 1209, 1210, 1211, 1212, 1213, 1214, 1215, 1216, 1217, 1218, 1219, 1220, 1221, 1222, 1223, 1224, 1225, 1226, 1227, 1228, 1229, 1230, 1231, -1, 1232, 1233, 1234, 1235, 1236, 1237, 1238, 1239, 1240, 1241, 1242, 1243, 1244, 1245, 1246, 1247, 1248, 1249, 1250, 1251, 1252, 1253, 1254, 1255, -1, 1256, 1257, 1258, 1259, 1260, 1261, 1262, 1263, 1264, 1265, 1266, 1267, 1268, 1269, 1270, 1271, 1272, 1273, 1274, 1275, 1276, 1277, 1278, 1279, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1280, 1281, 1282, 1283, -1, 1284, 1285, 1286, 1287, -1, 1288, 1289, 1290, 1291, -1, 1292, 1293, 1294, 1295, -1, -1, -1, -1, -1, -1, 1296, 1297, 1298, 1299, -1, 1300, 1301, 1302, 1303, -1, 1304, 1305, 1306, 1307, -1, 1308, 1309, 1310, 1311, -1, -1, -1, -1, -1, -1, 1312, 1313, 1314, 1315, -1, 1316, 1317, 1318, 1319, -1, 1320, 1321, 1322, 1323, -1, 1324, 1325, 1326, 1327, -1, -1, -1, -1, -1, -1, 1328, 1329, 1330, 1331, -1, 1332, 1333, 1334, 1335, -1, 1336, 1337, 1338, 1339, -1, 1340, 1341, 1342, 1343, -1, -1, -1, -1, -1, -1, 1344, 1345, 1346, 1347, -1, 1348, 1349, 1350, 1351, -1, 1352, 1353, 1354, 1355, -1, 1356, 1357, 1358, 1359, -1, 1360, 1361, 1362, 1363, 1364, 1365, 1366, 1367, 1368, 1369, 1370, 1371, 1372, 1373, 1374, 1375, 1376, 1377, 1378, 1379, 1380, 1381, 1382, 1383, -1, 1384, 1385, 1386, 1387, 1388, 1389, 1390, 1391, 1392, 1393, 1394, 1395, 1396, 1397, 1398, 1399, 1400, 1401, 1402, 1403, 1404, 1405, 1406, 1407, -1, 1408, 1409, 1410, 1411, 1412, 1413, 1414, 1415, 1416, 1417, 1418, 1419, 1420, 1421, 1422, 1423, 1424, 1425, 1426, 1427, 1428, 1429, 1430, 1431, -1, 1432, 1433, 1434, 1435, 1436, 1437, 1438, 1439, 1440, 1441, 1442, 1443, 1444, 1445, 1446, 1447, 1448, 1449, 1450, 1451, 1452, 1453, 1454, 1455, -1, -1, -1, -1, -1, -1, 1456, 1457, 1458, 1459, -1, 1460, 1461, 1462, 1463, -1, 1464, 1465, 1466, 1467, -1, 1468, 1469, 1470, 1471, -1, 1472, 1473, 1474, 1475, 1476, 1477, 1478, 1479, 1480, 1481, 1482, 1483, 1484, 1485, 1486, 1487, 1488, 1489, 1490, 1491, 1492, 1493, 1494, 1495, -1, 1496, 1497, 1498, 1499, 1500, 1501, 1502, 1503, 1504, 1505, 1506, 1507, 1508, 1509, 1510, 1511, 1512, 1513, 1514, 1515, 1516, 1517, 1518, 1519, -1, 1520, 1521, 1522, 1523, 1524, 1525, 1526, 1527, 1528, 1529, 1530, 1531, 1532, 1533, 1534, 1535, 1536, 1537, 1538, 1539, 1540, 1541, 1542, 1543, -1, 1544, 1545, 1546, 1547, 1548, 1549, 1550, 1551, 1552, 1553, 1554, 1555, 1556, 1557, 1558, 1559, 1560, 1561, 1562, 1563, 1564, 1565, 1566, 1567, -1, -1, -1, -1, -1, -1, 1568, 1569, 1570, 1571, -1, 1572, 1573, 1574, 1575, -1, 1576, 1577, 1578, 1579, -1, 1580, 1581, 1582, 1583, -1, 1584, 1585, 1586, 1587, 1588, 1589, 1590, 1591, 1592, 1593, 1594, 1595, 1596, 1597, 1598, 1599, 1600, 1601, 1602, 1603, 1604, 1605, 1606, 1607, -1, 1608, 1609, 1610, 1611, 1612, 1613, 1614, 1615, 1616, 1617, 1618, 1619, 1620, 1621, 1622, 1623, 1624, 1625, 1626, 1627, 1628, 1629, 1630, 1631, -1, 1632, 1633, 1634, 1635, 1636, 1637, 1638, 1639, 1640, 1641, 1642, 1643, 1644, 1645, 1646, 1647, 1648, 1649, 1650, 1651, 1652, 1653, 1654, 1655, -1, 1656, 1657, 1658, 1659, 1660, 1661, 1662, 1663, 1664, 1665, 1666, 1667, 1668, 1669, 1670, 1671, 1672, 1673, 1674, 1675, 1676, 1677, 1678, 1679, -1, -1, -1, -1, -1, -1, 1680, 1681, 1682, 1683, -1, 1684, 1685, 1686, 1687, -1, 1688, 1689, 1690, 1691, -1, 1692, 1693, 1694, 1695, -1, 1696, 1697, 1698, 1699, 1700, 1701, 1702, 1703, 1704, 1705, 1706, 1707, 1708, 1709, 1710, 1711, 1712, 1713, 1714, 1715, 1716, 1717, 1718, 1719, -1, 1720, 1721, 1722, 1723, 1724, 1725, 1726, 1727, 1728, 1729, 1730, 1731, 1732, 1733, 1734, 1735, 1736, 1737, 1738, 1739, 1740, 1741, 1742, 1743, -1, 1744, 1745, 1746, 1747, 1748, 1749, 1750, 1751, 1752, 1753, 1754, 1755, 1756, 1757, 1758, 1759, 1760, 1761, 1762, 1763, 1764, 1765, 1766, 1767, -1, 1768, 1769, 1770, 1771, 1772, 1773, 1774, 1775, 1776, 1777, 1778, 1779, 1780, 1781, 1782, 1783, 1784, 1785, 1786, 1787, 1788, 1789, 1790, 1791, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1792, 1793, 1794, 1795, -1, 1796, 1797, 1798, 1799, -1, 1800, 1801, 1802, 1803, -1, 1804, 1805, 1806, 1807, -1, -1, -1, -1, -1, -1, 1808, 1809, 1810, 1811, -1, 1812, 1813, 1814, 1815, -1, 1816, 1817, 1818, 1819, -1, 1820, 1821, 1822, 1823, -1, -1, -1, -1, -1, -1, 1824, 1825, 1826, 1827, -1, 1828, 1829, 1830, 1831, -1, 1832, 1833, 1834, 1835, -1, 1836, 1837, 1838, 1839, -1, -1, -1, -1, -1, -1, 1840, 1841, 1842, 1843, -1, 1844, 1845, 1846, 1847, -1, 1848, 1849, 1850, 1851, -1, 1852, 1853, 1854, 1855, -1, -1, -1, -1, -1, -1, 1856, 1857, 1858, 1859, -1, 1860, 1861, 1862, 1863, -1, 1864, 1865, 1866, 1867, -1, 1868, 1869, 1870, 1871, -1, 1872, 1873, 1874, 1875, 1876, 1877, 1878, 1879, 1880, 1881, 1882, 1883, 1884, 1885, 1886, 1887, 1888, 1889, 1890, 1891, 1892, 1893, 1894, 1895, -1, 1896, 1897, 1898, 1899, 1900, 1901, 1902, 1903, 1904, 1905, 1906, 1907, 1908, 1909, 1910, 1911, 1912, 1913, 1914, 1915, 1916, 1917, 1918, 1919, -1, 1920, 1921, 1922, 1923, 1924, 1925, 1926, 1927, 1928, 1929, 1930, 1931, 1932, 1933, 1934, 1935, 1936, 1937, 1938, 1939, 1940, 1941, 1942, 1943, -1, 1944, 1945, 1946, 1947, 1948, 1949, 1950, 1951, 1952, 1953, 1954, 1955, 1956, 1957, 1958, 1959, 1960, 1961, 1962, 1963, 1964, 1965, 1966, 1967, -1, -1, -1, -1, -1, -1, 1968, 1969, 1970, 1971, -1, 1972, 1973, 1974, 1975, -1, 1976, 1977, 1978, 1979, -1, 1980, 1981, 1982, 1983, -1, 1984, 1985, 1986, 1987, 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, -1, 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024, 2025, 2026, 2027, 2028, 2029, 2030, 2031, -1, 2032, 2033, 2034, 2035, 2036, 2037, 2038, 2039, 2040, 2041, 2042, 2043, 2044, 2045, 2046, 2047, 2048, 2049, 2050, 2051, 2052, 2053, 2054, 2055, -1, 2056, 2057, 2058, 2059, 2060, 2061, 2062, 2063, 2064, 2065, 2066, 2067, 2068, 2069, 2070, 2071, 2072, 2073, 2074, 2075, 2076, 2077, 2078, 2079, -1, -1, -1, -1, -1, -1, 2080, 2081, 2082, 2083, -1, 2084, 2085, 2086, 2087, -1, 2088, 2089, 2090, 2091, -1, 2092, 2093, 2094, 2095, -1, 2096, 2097, 2098, 2099, 2100, 2101, 2102, 2103, 2104, 2105, 2106, 2107, 2108, 2109, 2110, 2111, 2112, 2113, 2114, 2115, 2116, 2117, 2118, 2119, -1, 2120, 2121, 2122, 2123, 2124, 2125, 2126, 2127, 2128, 2129, 2130, 2131, 2132, 2133, 2134, 2135, 2136, 2137, 2138, 2139, 2140, 2141, 2142, 2143, -1, 2144, 2145, 2146, 2147, 2148, 2149, 2150, 2151, 2152, 2153, 2154, 2155, 2156, 2157, 2158, 2159, 2160, 2161, 2162, 2163, 2164, 2165, 2166, 2167, -1, 2168, 2169, 2170, 2171, 2172, 2173, 2174, 2175, 2176, 2177, 2178, 2179, 2180, 2181, 2182, 2183, 2184, 2185, 2186, 2187, 2188, 2189, 2190, 2191, -1, -1, -1, -1, -1, -1, 2192, 2193, 2194, 2195, -1, 2196, 2197, 2198, 2199, -1, 2200, 2201, 2202, 2203, -1, 2204, 2205, 2206, 2207, -1, 2208, 2209, 2210, 2211, 2212, 2213, 2214, 2215, 2216, 2217, 2218, 2219, 2220, 2221, 2222, 2223, 2224, 2225, 2226, 2227, 2228, 2229, 2230, 2231, -1, 2232, 2233, 2234, 2235, 2236, 2237, 2238, 2239, 2240, 2241, 2242, 2243, 2244, 2245, 2246, 2247, 2248, 2249, 2250, 2251, 2252, 2253, 2254, 2255, -1, 2256, 2257, 2258, 2259, 2260, 2261, 2262, 2263, 2264, 2265, 2266, 2267, 2268, 2269, 2270, 2271, 2272, 2273, 2274, 2275, 2276, 2277, 2278, 2279, -1, 2280, 2281, 2282, 2283, 2284, 2285, 2286, 2287, 2288, 2289, 2290, 2291, 2292, 2293, 2294, 2295, 2296, 2297, 2298, 2299, 2300, 2301, 2302, 2303};

#endif

// use ifdef for different encoding array schemes and list all out

//Mapping used to map $->0, A->1, C->2, G->3, T->4
char CharLookup[] = {0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, 2, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 4};

//Map m-chars to range (1 + STEP/4) * pow(4, STEP). To be used for occ tables
int encode_Mchars(char *str, int start)
{
    int index = 0;
    for (int8_t i = STEP - 1; i >= 0; --i)
    {
        index += pow(5, i) * (int)CharLookup[str[start + STEP - i - 1] - '$'];
    }
#ifdef DEBUG_ENCODE
    printf("%d,%d,%d\t%d\n", CharToOneByte[str[start] - '$'], CharToOneByte[str[start + 1] - '$'], CharToOneByte[str[start + 2] - '$'], index);
#endif
    return EncodedArray[index];
}

int encode_Mchars_wo_normalization(char *str, int start)
{
    int index = 0;
    for (int8_t i = STEP - 1; i >= 0; --i)
    {
        index += pow(5, i) * CharLookup[str[start + STEP - i - 1] - '$'];
    }
#ifdef DEBUG_ENCODE
    printf("%d,%d,%d\t%d\n", CharToOneByte[str[start] - '$'], CharToOneByte[str[start + 1] - '$'], CharToOneByte[str[start + 2] - '$'], index);
#endif
    return index;
}

//short reads (1<=length<=255) can be represented using 1 char
#define SHORT_READ 0

//long reads(255<length) need more than 1 char
//#define LONG_READ 0

//Suffix Array record (read_id, suffix_array) for each suffix
typedef struct
{
#ifdef SHORT_READ
    char *sa;
#endif
#ifdef LONG_READ
    int *sa;
#endif
    int *read_id;
} SuffixArray;

typedef struct
{
    int n;                                     //Total number of suffixes represented in fm_index
    int *row_map = new int[ALL_POSS_COMB_CNT]; //Mapping to the first record starting with F-value in sorted suffixes (A, T, C, G, $ -> total ALL_POSS_COMB_CNT combinations)

    //Data Structure Fix : Change usage from bwtString to bwtStrings
    int *bwtString; //Combined L-column values for all sorted suffixes
    //char **bwtStrings; //F-value wise L-coulmn values for all sorted suffixes

    // SuffixArray *suffix_array; //Suffix array for each suffix. Not calculated for time being

    uint32_t **occ_major; //Storing occ values every (d_major*i-1)th suffix
    int d_major;
} MStepFMIndex;

/*----------------------------------Index creation functions start-- ----------------------------------------------*/

//memory allocations for fm_index structure variables
void init_M_step_fm_index(MStepFMIndex *fm_index, int num_suffixes, int d_major)
{
#ifdef DEBUG
    //printf("Initializing fm index...\n\n");
    printf("Total Combinations Counts: %d\n", unsigned(TOTAL_COMB_CNT));
    printf("All Combinations Counts: %d\n", unsigned(ALL_POSS_COMB_CNT));

#endif
    fm_index->bwtString = (int *)malloc(num_suffixes * sizeof(int));
    //fm_index->bwtStrings = (char **)malloc((ALL_POSS_COMB_CNT - 1) * sizeof(char *));
    // fm_index->suffix_array = NULL;
    fm_index->n = num_suffixes;
    fm_index->d_major = d_major;
    int d_major_count = num_suffixes / d_major;
    fm_index->occ_major = (uint32_t **)malloc(d_major_count * sizeof(uint32_t *));
    for (int i = 0; i < d_major_count; ++i)
        fm_index->occ_major[i] = (uint32_t *)malloc(TOTAL_COMB_CNT * sizeof(uint32_t));

    for (int i = 0; i < ALL_POSS_COMB_CNT; ++i)
        fm_index->row_map[i] = EncodedArray[i];
}

//Calculates fm_index values from the list of sorted suffixes
void calculate_M_step_fm_index_from_sorted_suffixes(MStepFMIndex *fm_index, char *sorted_suffixes[], int suffix_length)
{
#ifdef DEBUG
    // printf("calculating fm_index from sorted...\n\n");
#endif
    int this_suffix_idx = 0;     //Array index of the current suffix currently being examined. Value in range (0, fm_index->n-1)
    int this_F_column_idx = 0;   //Array index of the F-value currently being examined. Value in range (0, ALL_POSS_COMB_CNT - 1)
    int previous_suffix_idx = 0; //Array index of the F-value previously being examined. Value in range (0, ALL_POSS_COMB_CNT - 1)

    //Iterate through all sorted suffixes to map first suffix with this_F_column_idx'th F-value into fm_index->row_map
    while (this_suffix_idx < fm_index->n && this_F_column_idx <= (ALL_POSS_COMB_CNT - 1))
    {
#ifdef DEBUG
        // printf("this suffix index: %d\n", this_suffix_idx);
        // printf("this F column index: %d\n", this_F_column_idx);
        fflush(stdout);
#endif
        //printf("(%d)Comparing %d and %d\n", this_suffix_idx, encode_Mchars(sorted_suffixes[this_suffix_idx], 0), EncodedArray[this_F_column_idx]);
        //If F-value of this suffix is same as F-value at this_F_column_idx, this is first such record and needs mapping in fm_index->row_map
        if (encode_Mchars(sorted_suffixes[this_suffix_idx], 0) == EncodedArray[this_F_column_idx])
        {
            fm_index->row_map[this_F_column_idx] = this_suffix_idx; //Map the record
            this_suffix_idx++;                                      //Move to examine next suffixes
        }

        //Keep iterating till we encounter a new F-value
        while (this_suffix_idx < fm_index->n && encode_Mchars(sorted_suffixes[this_suffix_idx], 0) == EncodedArray[this_F_column_idx])
        {
#ifdef DEBUG
            // printf("incrementing suffix index: %d\n", this_suffix_idx);
            fflush(stdout);
#endif
            this_suffix_idx++;
        }

        //Iteration paused. Check if new F-value found. Mapping would be performed for this F-value in fm_index->row_map if value found.
        //Else map wil be -1 for this F-value.
        //Move to examine next suffixes
        if (this_suffix_idx > previous_suffix_idx)
        {
            previous_suffix_idx = this_suffix_idx;
            this_F_column_idx = this_F_column_idx + 1;
        }
        else
        {
            fm_index->row_map[this_F_column_idx] = -1;
            this_F_column_idx = this_F_column_idx + 1;
            //printf("-1 initialization for row_map at idx %d\n", this_F_column_idx);
        }
        //printf("Done till %d with this_F_column_idx = %d\n", this_suffix_idx, this_F_column_idx);
    }

    //Since no suffixes exist for remaining F-values, store -1 for their fm_index->row_map's
    for (int i = this_F_column_idx; i < ALL_POSS_COMB_CNT; i++)
        fm_index->row_map[i] = -1;

    // #ifdef DEBUG
    //     printf("-----------------------------PRINTING VALID ROW-MAPS--------------------------\n");
    //     for (int i = 0; i < ALL_POSS_COMB_CNT; ++i)
    //     {
    //         if (fm_index->row_map[i] > -1)
    //             printf("%d   %d\n", EncodedArray[i], fm_index->row_map[i]);
    //     }
    //     printf("-------------------------------------------------------------------\n");
    // #endif

    //Encode L-values for each sorted suffix and store in fm_index->bwtString
    for (int i = 0; i < fm_index->n; ++i)
    {
        // printf("for index %d, encoded into Lterm:%d\n", i, encode_Mchars(sorted_suffixes[i], suffix_length - STEP));
        fm_index->bwtString[i] = encode_Mchars(sorted_suffixes[i], suffix_length - STEP);
        // printf("for index %d, bwtString is %d\n", i, fm_index->bwtString[i]);
        // printf("actually stored: %d\n", int(fm_index->bwtString[i]));
    }

#ifdef DEBUG_L_VALUES
    for (int i = 0; i < fm_index->n; i++)
        printf("%d : %d\n", i, fm_index->bwtString[i]);
#endif
#ifdef DEBUG
    printf("--------------------Printing Occ_major:-------------------------\n");
#endif

    int d_major_count = fm_index->n / fm_index->d_major; //Count of occ_major records possible with fm_index->n suffixes

    //Calculate occ_major values
    for (int i = 0; i < d_major_count; ++i)
    {
        puts("starting in for loop");
        for (int j = 0; j < TOTAL_COMB_CNT; ++j)
        {
            fm_index->occ_major[i][j] = 0;
        }
        for (int j = i * fm_index->d_major; j < i * fm_index->d_major + fm_index->d_major; j++)
        {
            //if(fm_index->bwtString[j] == (TOTAL_COMB_CNT - 1))
            //    printf("Increasing for (TOTAL_COMB_CNT - 1) at %dth L, current value=%d\n", j, fm_index->occ_major[i][fm_index->bwtString[j]]);
            fm_index->occ_major[i][fm_index->bwtString[j]]++;
        }
        if (i > 0)
        {
            for (int j = 0; j < TOTAL_COMB_CNT; ++j)
                fm_index->occ_major[i][j] = fm_index->occ_major[i][j] + fm_index->occ_major[i - 1][j];
        }

#ifdef DEBUG
        printf("[------%dth major Occ-------]\n", i);
        for (int j = 0; j < TOTAL_COMB_CNT; ++j)
        {
            if (fm_index->occ_major[i][j] != 0)
                printf("(%d)%d\t", j, fm_index->occ_major[i][j]);
        }
        printf("\n\n");
#endif
    }
}

/*----------------------------------Index Creation functions end------------------------------------------------*/
/*----------------------------------Query functions start------------------------------------------------*/

//Initializes search range for the first F-value in kmer (last M-chars of the query kmer). These values will be in terms of counts instead of actual array indexes
void init_search_interval(MStepFMIndex *fm_index, uint32_t F_term, int *search_start, int *search_end)
{
#ifdef DEBUG
    // printf("init_search_interval....\n");
#endif
    *search_start = fm_index->row_map[F_term]; //Get the array index of the first suffix with F-value = F_term
    //printf("Initialised value = %d\n", *search_start);
    if (*search_start != -1)
    {
        *search_end = 0;
        int i = F_term + 1;
        while (fm_index->row_map[i] == -1) //Iterate till we find next valid row_map. This would mark start of suffixes with next F-value
            ++i;

        //Get the array index of the first suffix with F-value = next F_term
        if (i < (ALL_POSS_COMB_CNT - 1))
            *search_end = fm_index->row_map[i];
        else
            *search_end = fm_index->n;

        //Normalize range in gterms of counts, instead of actual indexes
        *search_end = *search_end - *search_start - 1;
        *search_start = 0;
    }
    else
    {
        *search_start = -1;
        *search_end = -1;
    }
}

//Find the pre-calculated occ value 'count_at_start_idx' (using occ_major occ_values) nearest to target_idx. Also return the 'search_start_idx' for the search_start_idx'th suffix where values were pre-calculated
void find_nearest_Occ(MStepFMIndex *fm_index, uint32_t L_term, int target_idx, int *search_start_idx, int *count_at_start_idx)
{
#ifdef DEBUG
    // printf("L term is: %d\n", L_term);
    // printf("target_idx is: %d\n", target_idx);
#endif
    int nearest_d_major_start = (target_idx + 1) / fm_index->d_major - 1; //The array index of first major_occ value at or before the target_idx
    if (nearest_d_major_start > -1)
    {
        if (((target_idx + 1) % fm_index->d_major > fm_index->d_major / 2) && (target_idx < sizeof(fm_index->occ_major) / sizeof(fm_index->occ_major[0]))) // also check if exceeds last occ
        {
            // printf("closer to a greater idx\n");
            *search_start_idx = fm_index->d_major * (nearest_d_major_start + 2) - 1;
            *count_at_start_idx = fm_index->occ_major[nearest_d_major_start + 1][L_term];
        }
        else
        {
            // printf("closer to a lesser idx\n");
            *search_start_idx = fm_index->d_major * (nearest_d_major_start + 1) - 1;
            *count_at_start_idx = fm_index->occ_major[nearest_d_major_start][L_term];
        }
    }
    else // idx before the very first occ idx
    {
        // printf("before the first occ idx\n");
        *search_start_idx = fm_index->d_major - 1;
        *count_at_start_idx = fm_index->occ_major[0][L_term];
    }
    // #ifdef DEBUG
    // printf("looking for target index %d, nearest occ at index %d with count %d\n\n", target_idx, *search_start_idx, *count_at_start_idx);
    // #endif
}

//Update search intervals search_start and search_end for every new F_term and L_term values from the previous search interval. Also store exact count occ values at those search interval limits
void update_search_interval(MStepFMIndex *fm_index, uint32_t F_term, uint32_t L_term, int *search_start, int *search_end, int *count_lower_limit, int *count_upper_limit)
{
    int start_idx = fm_index->row_map[F_term] + *search_start; //First suffix for F-value = F_term to be searched
    int end_idx = fm_index->row_map[F_term] + *search_end;     //Last suffix for F-value = F_term to be searched
    printf("Inside : %d to %d\n", start_idx, end_idx);

    //Iterate the L-values in the search interval to find the first suffix (start_idx) with L-value = L_term
    while (start_idx <= end_idx && fm_index->bwtString[start_idx] != L_term)
    {
        printf("L term is: %d\n", L_term);
        printf("%d No match: %02x %02x\n", start_idx, fm_index->bwtString[start_idx], L_term);
        ++start_idx;
    }
    int temp_start_result, temp_end_result;
    printf("start idx: %d, end idx: %d\n", start_idx, end_idx);
    if (start_idx <= end_idx)
    {
        printf("start idx: %d is smaller than end idx: %d\n", start_idx, end_idx);
        //Check if this suffix's L-value is really L_term
        temp_start_result = fm_index->bwtString[start_idx] == L_term ? start_idx : -1;
        temp_end_result = temp_start_result;
    }
    else
    {
        *search_start = -1;
        *search_end = -1;
        return;
    }

    //Iterate the L-values in the search interval to find the last suffix (end_idx) with L-value = L_term
    while (start_idx <= end_idx && fm_index->bwtString[end_idx] != L_term)
        --end_idx;

    temp_end_result = (start_idx < end_idx && fm_index->bwtString[end_idx] == L_term) ? end_idx : temp_start_result;
    // printf("Before nearest Occ: %d to %d\n", temp_start_result, temp_end_result);

    int nearest_occ_idx_to_lower = 0, nearest_occ_idx_to_upper = 0;
    // printf("before looking for nearest occ, temp_start_result : %d\n", temp_start_result);
    // printf("before looking for nearest occ, temp_end_result : %d\n", temp_end_result);
    //FInd pre-calculated occ values (count_lower_limit, count_lower_limit) nearest to suffix ith array index temp_start_result and temp_end_result
    // printf("finding nearest occ for temp_start_result\n");
    find_nearest_Occ(fm_index, L_term, temp_start_result, &nearest_occ_idx_to_lower, count_lower_limit);
    // printf("finding nearest occ for temp_end_result\n");
    find_nearest_Occ(fm_index, L_term, temp_end_result, &nearest_occ_idx_to_upper, count_upper_limit);
    // printf("After nearest Occ count: %d to %d\n", *count_lower_limit, *count_upper_limit);

    // add or subtract while traveling to temp_start_result and temp_end_result idx from occ sentinel
    if (nearest_occ_idx_to_lower < temp_start_result) // nearest occ idx is smaller than current idx
    {
        for (int i = nearest_occ_idx_to_lower + 1; i <= temp_start_result; ++i)
        {
            // printf("now at index %d with L_term: %d\n", i, fm_index->bwtString[i]);
            *count_lower_limit += L_term == fm_index->bwtString[i] ? 1 : 0;
        }
    }
    else // nearest occ idx is greater than current idx
    {
        for (int i = nearest_occ_idx_to_lower; i > temp_start_result; --i)
        {
            // printf("now at index %d with L_term: %d\n", i, fm_index->bwtString[i]);
            *count_lower_limit -= L_term == fm_index->bwtString[i] ? 1 : 0;
        }
    }

    if (nearest_occ_idx_to_upper < temp_end_result) // nearest occ idx is smaller than current idx
    {
        // printf("NEAREST OCC IS SMALLER\n");
        for (int i = nearest_occ_idx_to_upper + 1; i <= temp_end_result; ++i)
        {
            // printf("now at index %d with L_term: %d\n", i, fm_index->bwtString[i]);
            *count_upper_limit += L_term == fm_index->bwtString[i] ? 1 : 0;
        }
    }
    else // nearest occ idx is larger than current idx
    {
        // printf("NEAREST OCC IS GREATER\n");
        for (int i = nearest_occ_idx_to_upper; i > temp_end_result; --i)
        {

            // printf("now at index %d with L_term: %d\n", i, fm_index->bwtString[i]);
            *count_upper_limit -= L_term == fm_index->bwtString[i] ? 1 : 0;
        }
    }
    // printf("Final nearest Occ count: %d to %d\n", *count_lower_limit, *count_upper_limit);
    *search_start = temp_start_result;
    *search_end = temp_end_result;
    // printf("search start: %d\n", *search_start);
    // printf("search end: %d\n", *search_end);
}

void query_Mstep_fm_index(MStepFMIndex *fm_index, char *kmer, int kmer_length, int *lower_limit, int *upper_limit)
{

    uint32_t F_term = encode_Mchars_wo_normalization(kmer, kmer_length - STEP); //First F-value. Last M-chars in kmer
    uint32_t L_term = encode_Mchars(kmer, kmer_length - STEP * 2);              //First L-value. Second-to-last M-chars in kmer
    // printf("F term is: %c, encoded into %d\n", kmer[kmer_length - STEP], F_term);
    // printf("L term is: %c, encoded into %d\n", kmer[kmer_length - STEP * 2], L_term);
    int search_rounds = (kmer_length + (STEP - 1)) / STEP - 1; //Number of search rounds required to cover whole kmer
    int search_start = 0;
    int search_end = 0;
    init_search_interval(fm_index, F_term, &search_start, &search_end); //Initialise search interval according to F_term
    int count_lower_limit = 0, count_upper_limit = 0;
    int i = 0;

    //Run M-char search rounds to cover whole kmer search
    for (i = 1; i <= search_rounds; ++i)
    {
        // printf("\nround %d\n", i);
        //Data Structure Fix : Map values to 0 ~ (TOTAL_COMB_CNT - 1)
        F_term = encode_Mchars_wo_normalization(kmer, kmer_length - STEP * i); //Since fm_index->row_map values currently map to 0 ~ ALL_POSS_COMB_CNT instead of 0 ~ (TOTAL_COMB_CNT - 1)
        L_term = encode_Mchars(kmer, kmer_length - STEP * i - STEP);           //Since fm_index->bwtString values are by default encoded to 0 ~ (TOTAL_COMB_CNT - 1)
        if (i > 1)
        {
            // printf("Before search limit update : map_result=%d limit : %d to %d\n", fm_index->row_map[F_term], count_lower_limit, count_upper_limit);
            search_start = count_lower_limit - 1;
            search_end = count_upper_limit - 1;
            // printf("Updated search limits : %d to %d\n", search_start, search_end);
        }
        if (search_start != -1 && search_end != -1)
        {
            // printf("gonna update search limits\n\n");
            update_search_interval(fm_index, F_term, L_term, &search_start, &search_end, &count_lower_limit, &count_upper_limit);
            //printf("Result limits : %d to %d with counts %d and %d\n", search_start, search_end, count_lower_limit, count_upper_limit);
        }
        else
        {
            break;
        }
    }
    if (i > search_rounds && search_start != -1 && search_end != -1)
    {
        search_start = fm_index->row_map[encode_Mchars_wo_normalization(kmer, 0)];
        search_end = search_start + count_lower_limit - 1;
        search_start += count_upper_limit - 1;
    }
    *lower_limit = search_start;
    *upper_limit = search_end;
}

/*----------------------------------Query functions end------------------------------------------------*/
#undef STEP