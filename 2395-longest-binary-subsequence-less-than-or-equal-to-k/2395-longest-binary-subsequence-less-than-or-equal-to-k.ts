function longestSubsequence(s: string, k: number): number {
    let sm = 0;
    let count = 0;
    let klength = Math.log2(k) + 1;
    for (let i = 0; i < s.length; i++) {
        const ch = s[s.length - 1 - i];
        if (ch === "1") {
            if (i < klength && sm + (1 << i) <= k) {
                sm += 1 << i;
            count++;
            }
        }else{
            count++;
        }
    }
    return count;
}