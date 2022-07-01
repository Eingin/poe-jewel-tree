#include "idadefs.h"

__int64 tintmt_init(unsigned int *a1, int *a2)
{
    int v2;           // r9d
    int v3;           // ecx
    int v4;           // edx
    unsigned int v5;  // ecx
    int v6;           // edx
    int v7;           // esi
    int v8;           // r8d
    int v9;           // eax
    int v10;          // ecx
    unsigned int v11; // r8d
    int v12;          // esi
    unsigned int v13; // edx
    int v14;          // ecx
    unsigned int v15; // r9d
    int v16;          // eax
    unsigned int v17; // ecx
    int v18;          // r8d
    unsigned int v19; // edx
    unsigned int v20; // ecx
    int v21;          // esi
    unsigned int v22; // r9d
    unsigned int v23; // ecx
    int v24;          // edx
    unsigned int v25; // esi
    int v26;          // r9d
    unsigned int v27; // edx
    unsigned int v28; // r8d
    int v29;          // ecx
    unsigned int v30; // edx
    int v31;          // eax
    int v32;          // r10d
    unsigned int v33; // ecx
    int v34;          // r9d
    int v35;          // edx
    int v36;          // r11d
    unsigned int v37; // ecx
    unsigned int v38; // r11d
    unsigned int v39; // eax
    int v40;          // r8d
    int v41;          // esi
    int v42;          // r10d
    unsigned int v43; // eax
    unsigned int v44; // r10d
    unsigned int v45; // ecx
    int v46;          // r9d
    int v47;          // edx
    int v48;          // esi
    unsigned int v49; // ecx
    unsigned int v50; // esi
    unsigned int v51; // eax
    int v52;          // r8d
    int v53;          // edx
    int v54;          // r10d
    unsigned int v55; // eax
    unsigned int v56; // r10d
    unsigned int v57; // ecx
    int v58;          // r9d
    int v59;          // edx
    int v60;          // r11d
    unsigned int v61; // ecx
    unsigned int v62; // r11d
    unsigned int v63; // eax
    int v64;          // r8d
    int v65;          // esi
    int v66;          // edx
    unsigned int v67; // eax
    unsigned int v68; // edx
    unsigned int v69; // ecx
    int v70;          // r9d
    int v71;          // ecx
    int v72;          // esi
    unsigned int v73; // r8d
    unsigned int v74; // esi
    unsigned int v75; // eax
    __int64 result;   // rax
    int v77;          // ecx

    a1[1] = 0x3793FDFF;
    a1[2] = 0xE47FA780;
    a1[3] = 0xCFA3723C;
    a1[4] = 0x40336050;
    v2 = *a2;
    v3 = *a2 - 1479325678;
    v4 = *a2 - 546879983;
    a1[2] = v3;
    v5 = 1664525 * (v3 ^ v4 ^ 0xE47FA780 ^ ((v3 ^ v4 ^ 0xE47FA780) >> 27));
    v6 = v5 + v2 - 546879983;
    a1[4] = v6;
    v7 = a2[1];
    v8 = v7 + v5 + 2;
    v9 = v7 + v5 + 1077108818;
    v10 = v7 + v5;
    v11 = 1664525 * (v8 ^ v6 ^ v9 ^ ((v8 ^ v6 ^ (unsigned int)v9) >> 27));
    v12 = v11 + v2 - 1479325675;
    v13 = 1664525 * ((v11 + 3) ^ v12 ^ (v11 + v10 + 1077108818) ^ (((v11 + 3) ^ v12 ^ (v11 + v10 + 1077108818)) >> 27));
    v14 = v13 + v10 + 2;
    v15 = 1664525 * (v13 ^ v14 ^ (v13 + v12) ^ ((v13 ^ v14 ^ (v13 + v12)) >> 27));
    v16 = v15 + v11 + 4;
    v17 = 1664525 * ((v15 + 1) ^ v16 ^ (v15 + v14) ^ (((v15 + 1) ^ v16 ^ (v15 + v14)) >> 27));
    v18 = v17 + v13 + 2;
    v19 = v17 + 2;
    v20 = 1664525 * ((v17 + 2) ^ v18 ^ (v17 + v16) ^ (((v17 + 2) ^ v18 ^ (v17 + v16)) >> 27));
    v21 = v20 + v15 + 4;
    v22 = v20 + 3;
    v23 = 1566083941 * ((v20 + v21 + v20 + v18 + 3) ^ ((v20 + v21 + v20 + v18 + 3) >> 27));
    v24 = v23 ^ v19;
    v25 = 1566083941 * ((v23 + v24 + (v23 ^ v21)) ^ ((v23 + v24 + (v23 ^ v21)) >> 27));
    v26 = (v25 - 1) ^ v22;
    v27 = 1566083941 * ((v25 + v26 + (v25 ^ v24) - 1) ^ ((v25 + v26 + (v25 ^ v24) - 1) >> 27));
    v28 = v27 - 2;
    v29 = (v27 - 2) ^ v23;
    v30 = 1566083941 * ((v29 + (v27 ^ v26) + v27 - 2) ^ ((v29 + (v27 ^ v26) + v27 - 2) >> 27));
    v31 = (v30 - 3) ^ (v25 - 1);
    v32 = (v30 - 3) ^ (2 * v30 - 6);
    v33 = ((v28 ^ v31 ^ (v30 ^ v29) & 0x7FFFFFFF) >> 1) ^ v32 ^ v28 ^ v31 ^ (v30 ^ v29) & 0x7FFFFFFF;
    v34 = v33 ^ (2 * v33);
    v35 = v32 ^ (v33 << 10);
    v36 = -((int)v33 & 1);
    v37 = v28 ^ v36 & 0x8F7011EE;
    v38 = v35 ^ v36 & 0xFC78FF1F;
    v39 = ((v38 ^ v37 ^ v31 & 0x7FFFFFFF) >> 1) ^ v34 ^ v38 ^ v37 ^ v31 & 0x7FFFFFFF;
    v40 = v39 ^ (2 * v39);
    v41 = v34 ^ (v39 << 10);
    v42 = -((int)v39 & 1);
    v43 = v38 ^ v42 & 0x8F7011EE;
    v44 = v41 ^ v42 & 0xFC78FF1F;
    v45 = ((v44 ^ v43 ^ v37 & 0x7FFFFFFF) >> 1) ^ v40 ^ v44 ^ v43 ^ v37 & 0x7FFFFFFF;
    v46 = v45 ^ (2 * v45);
    v47 = v40 ^ (v45 << 10);
    v48 = -((int)v45 & 1);
    v49 = v44 ^ v48 & 0x8F7011EE;
    v50 = v47 ^ v48 & 0xFC78FF1F;
    v51 = ((v50 ^ v49 ^ v43 & 0x7FFFFFFF) >> 1) ^ v46 ^ v50 ^ v49 ^ v43 & 0x7FFFFFFF;
    v52 = v51 ^ (2 * v51);
    v53 = v46 ^ (v51 << 10);
    v54 = -((int)v51 & 1);
    v55 = v50 ^ v54 & 0x8F7011EE;
    v56 = v53 ^ v54 & 0xFC78FF1F;
    v57 = ((v56 ^ v55 ^ v49 & 0x7FFFFFFF) >> 1) ^ v52 ^ v56 ^ v55 ^ v49 & 0x7FFFFFFF;
    v58 = v57 ^ (2 * v57);
    v59 = v52 ^ (v57 << 10);
    v60 = -((int)v57 & 1);
    v61 = v56 ^ v60 & 0x8F7011EE;
    v62 = v59 ^ v60 & 0xFC78FF1F;
    v63 = ((v62 ^ v61 ^ v55 & 0x7FFFFFFF) >> 1) ^ v58 ^ v62 ^ v61 ^ v55 & 0x7FFFFFFF;
    v64 = v63 ^ (2 * v63);
    v65 = v58 ^ (v63 << 10);
    v66 = -((int)v63 & 1);
    v67 = v62 ^ v66 & 0x8F7011EE;
    v68 = v65 ^ v66 & 0xFC78FF1F;
    v69 = ((v68 ^ v67 ^ v61 & 0x7FFFFFFF) >> 1) ^ v64 ^ v68 ^ v67 ^ v61 & 0x7FFFFFFF;
    LOBYTE(v65) = v69;
    v70 = v69 ^ (2 * v69);
    v71 = v64 ^ (v69 << 10);
    v72 = -(v65 & 1);
    v73 = v68 ^ v72 & 0x8F7011EE;
    v74 = v71 ^ v72 & 0xFC78FF1F;
    v75 = ((v74 ^ v73 ^ v67 & 0x7FFFFFFF) >> 1) ^ v70 ^ v74 ^ v73 ^ v67 & 0x7FFFFFFF;
    LOBYTE(v71) = v75;
    a1[0] += 8;
    a1[4] = v75;
    result = v70 ^ (v75 << 10);
    v77 = -(v71 & 1);
    a1[1] = v73;
    a1[2] = v74 ^ v77 & 0x8F7011EE;
    a1[3] = result ^ v77 & 0xFC78FF1F;
    return result;
}

__int64 tintmt_next(unsigned int *a2, unsigned int a4)
{
    int v5;           // ecx
    unsigned int v6;  // r11d
    int v7;           // r14d
    unsigned int v8;  // r15d
    unsigned int v9;  // r13d
    unsigned int v10; // ebx
    unsigned int v11; // r12d
    unsigned int v12; // eax
    int v13;          // edx
    unsigned int v14; // edi
    unsigned int v15; // edx
    int v16;          // r9d
    int v17;          // ebx
    unsigned int v18; // ecx
    unsigned int v19; // eax
    int v20;          // eax

    v5 = a4 - 1;
    if (v5 == -1)
    {
        v15 = a2[2];
        v16 = a2[3];
        v17 = a2[4] ^ (2 * a2[4]);
        v18 = ((a2[1] & 0x7FFFFFFF ^ v16 ^ v15) >> 1) ^ v17 ^ a2[1] & 0x7FFFFFFF ^ v16 ^ v15;
        a2[1] = v15;
        a2[4] = v18;
        a2[2] = v16 ^ -((int)v18 & 1) & 0x8F7011EE;
        v19 = v17 ^ (v18 << 10) ^ -((int)v18 & 1) & 0xFC78FF1F;
        a2[3] = v19;
        v20 = (v15 + (v19 >> 8)) ^ v18 ^ -((int)(v15 + (v19 >> 8)) & 1) & 0x3793FDFF;
        ++*a2;
    }
    else
    {
        v6 = v5 + 1;
        if (v5)
        {
            v7 = *a2;
            v8 = a2[1];
            v9 = a2[4];
            v10 = a2[2];
            v11 = a2[3];
            do
            {
                v12 = v8;
                v8 = v10;
                ++v7;
                v13 = v9 ^ (2 * v9);
                v9 = v12 & 0x7FFFFFFF ^ v11 ^ v10 ^ v13 ^ ((v12 & 0x7FFFFFFF ^ v11 ^ v10) >> 1);
                v10 = v11 ^ -(((unsigned __int8)(v12 ^ v11 ^ v10 ^ v13) ^ (unsigned __int8)((v12 & 0x7FFFFFFF ^ v11 ^ v10) >> 1)) & 1) & 0x8F7011EE;
                v11 = v13 ^ (v9 << 10) ^ -((int)v9 & 1) & 0xFC78FF1F;
                v14 = v9 ^ (v8 + (v11 >> 8)) ^ -((int)(v8 + (v11 >> 8)) & 1) & 0x3793FDFF;
            } while (v14 / v6 >= 0xFFFFFFFF / v6 && 0xFFFFFFFF % v6 != v5);
            a2[1] = v8;
            a2[4] = v9;
            a2[2] = v10;
            a2[3] = v11;
            *a2 = v7;
        }
        else
        {
            v14 = 0;
        }
        v20 = v14 % v6;
    }
    return (unsigned int)(v20);
}