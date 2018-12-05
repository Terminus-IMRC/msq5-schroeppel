#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <x86intrin.h>
#include <assert.h>

typedef int_fast8_t cell_t;

#define ORDER 5
#define SUM (ORDER * (ORDER*ORDER - 1) / 2)

int main(void)
{
    cell_t
        B, J, L, K, F,
        V, C, T, H,
        R, N, A, P, S,
        W, I, U, D,
        G, M, Q, O, E;
    int i, ikl, imn, irs, itu, ivw;
    uint32_t using = ((uint32_t) 0);
    uint32_t count[(ORDER*ORDER) >> 1] = {0};

#define used(x)    (using &  (((uint32_t) 1) << (x)))
#define acquire(x) (using |= (((uint32_t) 1) << (x)))
#define release(x) (using ^= (((uint32_t) 1) << (x)))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define print_square() \
    do { \
        printf("%2" PRId8 " %2" PRId8 " %2" PRId8 " %2" PRId8 " %2" PRId8 "\n", B, J, L, K, F); \
        printf("%2" PRId8 " %2" PRId8 " %2" PRId8 " %2" PRId8 " %2" PRId8 "\n", V, C, T, H, tmpx); \
        printf("%2" PRId8 " %2" PRId8 " %2" PRId8 " %2" PRId8 " %2" PRId8 "\n", R, N, A, P, S); \
        printf("%2" PRId8 " %2" PRId8 " %2" PRId8 " %2" PRId8 " %2" PRId8 "\n", W, I, U, D, tmp1); \
        printf("%2" PRId8 " %2" PRId8 " %2" PRId8 " %2" PRId8 " %2" PRId8 "\n", G, M, Q, O, E); \
    } while (0)

#define verify_msq() \
    do { \
        assert(B + J + L + K + F == SUM); \
        assert(V + C + T + H + tmpx == SUM); \
        assert(R + N + A + P + S == SUM); \
        assert(W + I + U + D + tmp1 == SUM); \
        assert(G + M + Q + O + E == SUM); \
        assert(B + V + R + W + G == SUM); \
        assert(J + C + N + I + M == SUM); \
        assert(L + T + A + U + Q == SUM); \
        assert(K + H + P + D + O == SUM); \
        assert(F + tmpx + S + tmp1 + E == SUM); \
        assert(B + C + A + D + E == SUM); \
        assert(F + H + A + I + G == SUM); \
    } while (0)

    //for (A = 0; A <= ((ORDER*ORDER) >> 1); A ++) {
    A = 0; {
        acquire(A);
        for (B = 0; B < ORDER*ORDER; B ++) {
            if (used(B))
                continue;
            acquire(B);
            for (C = B + 1; C < ORDER*ORDER; C ++) {
                if (used(C))
                    continue;
                acquire(C);
                for (D = C + 1; D < ORDER*ORDER; D ++) {
                    if (used(D))
                        continue;
                    {
                        const cell_t tmp = SUM - A - B - C - D;
                        if (!(B < tmp && tmp < ORDER*ORDER))
                            continue;
                        else if (tmp == D || used(tmp))
                            continue;
                        E = tmp;
                    }
                    acquire(D);
                    acquire(E);
                    for (F = B + 1; F < ORDER*ORDER; F ++) {
                        if (used(F))
                            continue;
                        acquire(F);
                        for (G = F + 1; G < ORDER*ORDER; G ++) {
                            if (used(G))
                                continue;
                            acquire(G);
                            for (H = B + 1; H < ORDER*ORDER; H ++) {
                                if (used(H))
                                    continue;
                                {
                                    const cell_t tmp = SUM - A - F - G - H;
                                    if (!(B < tmp && tmp < ORDER*ORDER))
                                        continue;
                                    else if (tmp == H || used(tmp))
                                        continue;
                                    I = tmp;
                                }
                                acquire(H);
                                acquire(I);
                                for (J = 0; J < ORDER*ORDER; J ++) {
                                    if (used(J))
                                        continue;
                                    const cell_t K_plus_L = SUM - B - F - J;
                                    if (!(0 <= K_plus_L && K_plus_L <= (ORDER*ORDER-1) + (ORDER*ORDER-2)))
                                        continue;
                                    const cell_t M_plus_N = SUM - C - I - J;
                                    if (!(0 <= M_plus_N && M_plus_N <= (ORDER*ORDER-1) + (ORDER*ORDER-2)))
                                        continue;
                                    acquire(J);
                                    for (K = min(K_plus_L, ORDER*ORDER - 1); K >= 0; K --) {
                                        if (used(K))
                                            continue;
                                        {
                                            const cell_t tmp = K_plus_L - K;
                                            if (!(0 <= tmp && tmp < ORDER*ORDER))
                                                continue;
                                            else if (tmp == K || used(tmp))
                                                continue;
                                            L = tmp;
                                        }
                                        acquire(K);
                                        acquire(L);
                                        const cell_t K_xor_L = K ^ L;
                                        for (ikl = 0; ikl < 2; ikl ++, K ^= K_xor_L, L ^= K_xor_L) {
                                            for (M = min(M_plus_N, ORDER*ORDER - 1); M >= 0; M --) {
                                                if (used(M))
                                                    continue;
                                                {
                                                    const cell_t tmp = M_plus_N - M;
                                                    if (!(0 <= tmp && tmp < ORDER*ORDER))
                                                        continue;
                                                    else if (tmp == M || used(tmp))
                                                        continue;
                                                    N = tmp;
                                                }
                                                acquire(M);
                                                acquire(N);
                                                const cell_t M_xor_N = M ^ N;
                                                for (imn = 0; imn < 2; imn ++, M ^= M_xor_N, N ^= M_xor_N) {
                                                    for (O = 0; O < ORDER*ORDER; O ++) {
                                                        if (used(O))
                                                            continue;
                                                        {
                                                            const cell_t tmp = SUM - D - H - K - O;
                                                            if (!(0 <= tmp && tmp < ORDER*ORDER))
                                                                continue;
                                                            else if (tmp == O || used(tmp))
                                                                continue;
                                                            P = tmp;
                                                        }
                                                        const cell_t R_plus_S = SUM - A - N - P;
                                                        if (!(0 <= R_plus_S && R_plus_S <= (ORDER*ORDER-1) + (ORDER*ORDER-2)))
                                                            continue;
                                                        {
                                                            const cell_t tmp = SUM - E - G - M - O;
                                                            if (!(0 <= tmp && tmp < ORDER*ORDER))
                                                                continue;
                                                            else if (tmp == O || tmp == P || used(tmp))
                                                                continue;
                                                            Q = tmp;
                                                        }
                                                        const cell_t T_plus_U = SUM - A - L - Q;
                                                        if (!(0 <= T_plus_U && T_plus_U <= (ORDER*ORDER-1) + (ORDER*ORDER-2)))
                                                            continue;
                                                        acquire(O);
                                                        acquire(P);
                                                        acquire(Q);

                                                        /* Start of page 6 */

                                                        for (R = min(R_plus_S, ORDER*ORDER - 1); R >= 0; R --) {
                                                            if (used(R))
                                                                continue;
                                                            const cell_t V_plus_W = SUM - B - G - R;
                                                            if (!(0 <= V_plus_W && V_plus_W <= (ORDER*ORDER-1) + (ORDER*ORDER-2)))
                                                                continue;
                                                            {
                                                                const cell_t tmp = R_plus_S - R;
                                                                if (!(0 <= tmp && tmp < ORDER*ORDER))
                                                                    continue;
                                                                else if (tmp == R || used(tmp))
                                                                    continue;
                                                                S = tmp;
                                                            }
                                                            acquire(R);
                                                            acquire(S);
                                                            const cell_t R_xor_S = R ^ S;
                                                            for (irs = 0; irs < 2; irs ++, R ^= R_xor_S, S ^= R_xor_S) {
                                                                /* Now R and S are ready. */
                                                                for (T = min(T_plus_U, ORDER*ORDER - 1); T >= 0; T --) {
                                                                    if (used(T))
                                                                        continue;
                                                                    {
                                                                        const cell_t tmp = T_plus_U - T;
                                                                        if (!(0 <= tmp && tmp < ORDER*ORDER))
                                                                            continue;
                                                                        else if (tmp == T || used(tmp))
                                                                            continue;
                                                                        U = tmp;
                                                                    }
                                                                    acquire(T);
                                                                    acquire(U);
                                                                    const cell_t T_xor_U = T ^ U;
                                                                    for (itu = 0; itu < 2; itu ++, T ^= T_xor_U, U ^= T_xor_U) {
                                                                        /* Now T and U are ready. */
                                                                        for (V = min(V_plus_W, ORDER*ORDER - 1); V >= 0; V --) {
                                                                            if (used(V))
                                                                                continue;
                                                                            {
                                                                                const cell_t tmp = V_plus_W - V;
                                                                                if (!(0 <= tmp && tmp < ORDER*ORDER))
                                                                                    continue;
                                                                                else if (tmp == V || used(tmp))
                                                                                    continue;
                                                                                W = tmp;
                                                                            }
                                                                            acquire(V);
                                                                            acquire(W);
                                                                            const cell_t V_xor_W = V ^ W;
                                                                            for (ivw = 0; ivw < 2; ivw ++, V ^= V_xor_W, W ^= V_xor_W) {
                                                                                /* Now V and W are ready. */
                                                                                const cell_t tmpx = SUM - C - H - T - V;
                                                                                if (!(0 <= tmpx && tmpx < ORDER*ORDER))
                                                                                    continue;
                                                                                else if (used(tmpx))
                                                                                    continue;

                                                                                const cell_t tmp1 = SUM - D - I - U - W;
                                                                                if (!(0 <= tmp1 && tmp1 < ORDER*ORDER))
                                                                                    continue;
                                                                                else if (tmp1 == tmpx || used(tmp1))
                                                                                    continue;
                                                                                const cell_t tmp2 = SUM - E - F - S - tmpx;
#if 0
                                                                                if (tmp2 != tmp1) {
                                                                                    fprintf(stderr, "%s:%d: Schroeppel says it's an error\n", __FILE__, __LINE__);
                                                                                    return 1;
                                                                                }
#else
                                                                                if (tmp2 != tmp1)
                                                                                    continue;
#endif
                                                                                //printf("MSQ with A=%d count=%d\n", A, count[A]);
                                                                                //print_square();
                                                                                verify_msq();
                                                                                if (count[0] >= 1091448) {
                                                                                    fprintf(stderr, "aaa\n");
                                                                                }
                                                                                //printf("0x%08x %d\n", using, _popcnt64((uint64_t) using)); break;
                                                                                //assert(_popcnt64((uint64_t) using) == 23); break;
                                                                                count[A] ++;
                                                                            }
                                                                            release(W);
                                                                            release(V);
                                                                        }
                                                                    }
                                                                    release(U);
                                                                    release(T);
                                                                }
                                                            }
                                                            release(S);
                                                            release(R);
                                                        }

                                                        /* End of page 6 */

                                                        release(Q);
                                                        release(P);
                                                        release(O);
                                                    }
                                                }
                                                release(N);
                                                release(M);
                                            }
                                        }
                                        release(L);
                                        release(K);
                                    }
                                    release(J);
                                }
                                release(I);
                                release(H);
                            }
                            release(G);
                        }
                        release(F);
                    }
                    release(E);
                    release(D);
                }
                release(C);
            }
            release(B);
        }
        release(A);
    }

    for (i = 0; i < ((ORDER*ORDER) >> 1); i ++)
        printf("count of A=%2d: %" PRIu32 "\n", i, count[i]);
    printf("using = 0x%08x\n", using);
    return 0;
}
