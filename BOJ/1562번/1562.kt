fun main() {
    val n = readLine()!!.toInt()
    val mod = 1e9.toInt()
    val max = 1 shl 10
    val dp = Array(n + 1) { Array(10) { LongArray(max) { 0 } } }
    for (num in 1..9) dp[1][num][1 shl num] = 1
    for (index in 2..n) {
        for (num in 0..9) {
            when (num) {
                0 -> {
                    for (prev in 0 until max) {
                        if (dp[index - 1][1][prev] == 0L) continue
                        dp[index][num][prev or (1 shl num)] = (dp[index][num][prev or (1 shl num)] + dp[index - 1][1][prev]) % mod
                    }
                }
                in 1..8 -> {
                    for (prev in 0 until max) {
                        if (dp[index - 1][num - 1][prev] == 0L) continue
                        dp[index][num][prev or (1 shl num)] = (dp[index][num][prev or (1 shl num)] + dp[index - 1][num - 1][prev]) % mod
                    }
                    for (prev in 0 until max) {
                        if (dp[index - 1][num + 1][prev] == 0L) continue
                        dp[index][num][prev or (1 shl num)] = (dp[index][num][prev or (1 shl num)] + dp[index - 1][num + 1][prev]) % mod
                    }
                }
                9 -> {
                    for (prev in 0 until max) {
                        if (dp[index - 1][8][prev] == 0L) continue
                        dp[index][num][prev or (1 shl num)] = (dp[index][num][prev or (1 shl num)] + dp[index - 1][8][prev]) % mod
                    }
                }
            }
        }
    }
    var answer = 0L
    for (num in 0..9) answer = (answer + dp[n][num][max - 1]) % mod
    print("$answer")
}