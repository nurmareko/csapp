
void goto_cond(long a, long *p) {
    if (p == 0)
        goto done;
    if (*P >= a)
        goto done;
    *p = a;
done:
}
