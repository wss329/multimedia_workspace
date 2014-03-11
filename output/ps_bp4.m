function p = ps_bp4()
Ia=[0.413767,0.414939,0.415549,0.416237,0.415393,0.418201,0.415968,0.418609,0.418721,0.415704,0.421217,0.419211,0.422087,0.423142,0.424887,0.423626,0.424554,0.426665,0.428987,0.427443,0.425166,0.429615,0.428124,0.428323,0.429455,0.431332,0.432137,0.434035,0.431771,0.434963,0.436438,0.433361,0.437162,0.437915,0.438298,0.441755,0.440194,0.441148,0.438753,0.442745,0.442104,0.442083,0.445399,0.446051,0.446543,0.446219,0.445639,0.450751,0.448792,0.447639,0.449842,0.450088,0.451144,0.453879,0.453017,0.456642,0.453768,0.452770,0.455514,0.458099,0.458921,0.458215,0.457555,0.460276,0.460436,0.462439,0.463314,0.464797,0.463609,0.462572,0.463229,0.465086,0.468172,0.469262,0.466418,0.470564,0.470985,0.469593,0.469156,0.469571,0.473428,0.475301,0.475751,0.473845,0.476245,0.475394,0.476971,0.479238,0.479685,0.480913,0.483354,0.483086,0.484264,0.480985,0.486161,0.481594,0.487043,0.484339,0.490955,0.488408,0.489207,0.489434,0.490992,0.489731,0.490943,0.493245,0.493466,0.494134,0.494006,0.497665,0.499802,0.498591,0.495600,0.498308,0.500783,0.500221,0.501373,0.501240,0.502868,0.503993,0.503936,0.503719,0.507950,0.506532,0.507665,0.506596,0.507656,0.509547,0.510132,0.511647,0.512968,0.514485,0.514767,0.512751,0.516484,0.514482,0.516934,0.516671,0.517642,0.519051,0.521472,0.521909,0.521750,0.521861,0.523348,0.523236,0.523292,0.526639,0.526294,0.529487,0.528784,0.526291,0.529748,0.529751,0.531120,0.531465,0.534549,0.533401,0.535607,0.534376,0.537933,0.537430,0.539517,0.539092,0.539385,0.537719,0.540966,0.541012,0.543415,0.546923,0.544380,0.547028,0.546913,0.546114,0.549173,0.549191,0.551984,0.551145,0.553065,0.548450,0.551391,0.554608,0.554259,0.555680,0.556407,0.557680,0.556000,0.557105,0.559942,0.557860,0.563427,0.562620,0.560247,0.563107,0.562565,0.564797,0.563860,0.566891,0.567409,0.567042,0.570455,0.571810,0.567095,0.572213,0.574258,0.573045,0.571844,0.571821,0.576329,0.576095,0.576259,0.577717,0.578936,0.582888,0.579231,0.581743,0.580804,0.582413,0.581543,0.581550,0.585158,0.586502,0.582595,0.588697,0.588941,0.590179,0.592734,0.590775,0.592296,0.594184,0.596235,0.595984,0.596803,0.596587,0.600676,0.595884,0.595202,0.598734,0.599329,0.599630,0.603004,0.604718,0.602574,0.603002,0.601701,0.604825,0.606578,0.607878,0.609215,0.612789,0.610817,0.609357,0.611309,0.611396,0.610995,0.615761,0.614130,0.613991,0.616871,0.616436,0.617217,0.619180,0.622430,0.621499,0.621304,0.624019,0.623518,0.624301,0.622776,0.625514,0.625723,0.626169,0.628751,0.628966,0.631905,0.629632,0.634562,0.632666,0.632851,0.636168,0.639912,0.632782,0.637573,0.637187,0.638442,0.638813,0.641171,0.640392,0.644537,0.643661,0.645702,0.642976,0.646611,0.645337,0.648337,0.648470,0.650981,0.646601,0.650912,0.653906,0.651728,0.650717,0.656303,0.655578,0.654624,0.656282,0.654637,0.657998,0.660424,0.659580,0.661141,0.660446,0.663345,0.662699,0.662674,0.661727,0.663401,0.666334,0.667387,0.668182,0.667102,0.670805,0.668542,0.671359,0.673182,0.672996,0.673629,0.676909,0.675878,0.675170,0.676657,0.679323,0.679099,0.678588,0.679759,0.679626,0.683029,0.682896,0.684166,0.684985,0.683629,0.682077,0.689102,0.687155,0.686578,0.688194,0.691199,0.691220,0.691991,0.692903,0.692745,0.694301,0.694858,0.692534,0.697294,0.698085,0.697046,0.699591,0.699199,0.698293,0.703736,0.702727,0.704296,0.703457,0.701971,0.706226,0.708731,0.705228,0.708540,0.708685,0.710244,0.707675,0.713162,0.713458,0.713573,0.713328,0.713777,0.717211,0.715466,0.716288,0.719091,0.718743,0.721106,0.720570,0.720545,0.719539,0.722236,0.721894,0.725507,0.722668,0.726195,0.726995,0.728471,0.728159,0.725907,0.733370,0.728914,0.732794,0.730096,0.730974,];
Ie=[0.124855,0.123145,0.124889,0.124902,0.122192,0.127405,0.122741,0.125735,0.125104,0.122792,0.125083,0.125519,0.126740,0.125993,0.128886,0.128538,0.129266,0.127993,0.128905,0.131227,0.126119,0.130572,0.129686,0.128683,0.131670,0.129963,0.131221,0.132139,0.128719,0.131278,0.129838,0.131409,0.132365,0.134983,0.132006,0.134955,0.136073,0.135040,0.133664,0.136359,0.135631,0.133506,0.136843,0.136145,0.136546,0.137939,0.135922,0.138384,0.137341,0.138844,0.138349,0.140893,0.138383,0.141586,0.139741,0.141985,0.140225,0.140489,0.139961,0.143271,0.145471,0.142132,0.140350,0.142546,0.143963,0.143845,0.144057,0.146044,0.144040,0.144079,0.143414,0.145300,0.148290,0.147980,0.144145,0.148084,0.148086,0.147640,0.147171,0.147774,0.149685,0.150179,0.147843,0.151931,0.153844,0.152229,0.152798,0.152463,0.151994,0.152969,0.154393,0.154055,0.152763,0.153084,0.155825,0.151131,0.156609,0.151471,0.158008,0.157225,0.156457,0.156279,0.156611,0.156311,0.154542,0.159387,0.158208,0.159499,0.159780,0.160418,0.159284,0.157508,0.158020,0.160378,0.162518,0.162247,0.163943,0.163464,0.162767,0.162874,0.163730,0.164044,0.160897,0.162429,0.166368,0.164124,0.164272,0.165696,0.166842,0.166807,0.166688,0.170285,0.168526,0.165883,0.167986,0.169598,0.167753,0.169374,0.168609,0.173187,0.170969,0.171547,0.171063,0.171127,0.171002,0.171252,0.167957,0.172712,0.171992,0.176091,0.171969,0.173248,0.174780,0.174300,0.175908,0.175053,0.176649,0.175227,0.176050,0.177273,0.178759,0.178647,0.179697,0.180405,0.178144,0.178033,0.179831,0.178878,0.179600,0.182807,0.181800,0.181733,0.183231,0.182707,0.183283,0.183804,0.184326,0.185247,0.184729,0.180797,0.182628,0.184180,0.188549,0.186552,0.183731,0.187807,0.185176,0.189152,0.184949,0.188387,0.188747,0.190120,0.186078,0.190894,0.189194,0.189969,0.189646,0.191212,0.192633,0.191880,0.190486,0.194275,0.191120,0.191691,0.196130,0.194929,0.192906,0.196699,0.195526,0.194847,0.193722,0.195322,0.193669,0.198625,0.199951,0.198463,0.197421,0.198646,0.197378,0.196727,0.197290,0.198241,0.194141,0.202365,0.200546,0.202041,0.203939,0.200869,0.201626,0.203361,0.203646,0.203661,0.203594,0.205829,0.208344,0.202576,0.202809,0.206346,0.205609,0.205530,0.208418,0.208355,0.207433,0.207269,0.206730,0.207904,0.210321,0.209802,0.210364,0.212982,0.210906,0.210482,0.210497,0.211108,0.212049,0.213536,0.211204,0.212679,0.213487,0.214174,0.213943,0.213796,0.216493,0.215249,0.217174,0.216969,0.215978,0.215987,0.218440,0.217227,0.216993,0.216325,0.217654,0.217016,0.218597,0.219793,0.220027,0.219953,0.220855,0.222942,0.221582,0.220760,0.222180,0.221097,0.223992,0.221847,0.225215,0.222485,0.224530,0.225049,0.225775,0.226344,0.225185,0.224068,0.227039,0.226393,0.226985,0.225412,0.230237,0.230312,0.228482,0.226986,0.229507,0.230206,0.226328,0.231247,0.231671,0.232531,0.230938,0.232245,0.233990,0.231362,0.232594,0.233076,0.232933,0.230248,0.232989,0.233713,0.235662,0.235897,0.235949,0.235494,0.233367,0.235224,0.238021,0.237523,0.238778,0.238112,0.237917,0.237661,0.238622,0.242328,0.242258,0.240463,0.241018,0.237624,0.241372,0.240817,0.243123,0.242998,0.241701,0.239417,0.245489,0.243422,0.243509,0.242763,0.246466,0.245611,0.243947,0.245540,0.246563,0.247250,0.246638,0.246288,0.246518,0.245481,0.245682,0.247458,0.252157,0.249501,0.248338,0.251429,0.250266,0.248824,0.249281,0.251208,0.249415,0.250881,0.253026,0.252741,0.250908,0.251929,0.253401,0.252961,0.252138,0.253901,0.251570,0.255163,0.254977,0.255516,0.256174,0.256277,0.256919,0.255607,0.256583,0.253246,0.260006,0.256583,0.258121,0.258516,0.258721,0.259689,0.257821,0.259270,0.257588,0.262461,0.258460,0.258509,0.259754,0.262746,];
p=polyfit(Ia,Ie,3);
xi = 0:0.01:1;
yi = polyval(p,xi);
plot(Ie, Ia,'o','LineWidth',2,'Color',[0 0 0]);
hold on;
plot(yi,xi,'LineWidth',1);
axis([0,1,0,1]);
grid on;
hold off;