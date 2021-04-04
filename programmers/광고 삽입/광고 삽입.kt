class Solution {
    fun getTime(pow: Int): Int {
        when {
            pow == 0 -> return 1
            else -> return 60 * getTime(pow - 1)
        }
    }
    fun timeToSeconds(time: String): Int {
        var res = 0
        time.split(":").forEachIndexed { index, t -> 
            res += t.toInt() * getTime(2 - index)
        }
        return res
    }
    fun solution(play_time: String, adv_time: String, logs: Array<String>): String {
        val limit = 360001
        val playTime = timeToSeconds(play_time)
        val advTime = timeToSeconds(adv_time)
        val playSequence = LongArray(limit) { 0 }

        logs.forEach { log -> 
            val (logStart, logEnd) = log.split("-").map { timeToSeconds(it) }
            playSequence[logStart + 1]++
            playSequence[logEnd + 1]--
        }
        
        for (index in 1 until limit) {
            playSequence[index] += playSequence[index - 1]
        }
        
        val playPrefix = LongArray(limit) { playSequence[0] }
        for (index in 1 until limit) {
            playPrefix[index] = playPrefix[index - 1] + playSequence[index]
        }
        
        var startAdv = 0
        var endAdv = advTime
        var score: Long = 0
        var result = playTime
        while (endAdv <= playTime) {
            val currentScore: Long = playPrefix[endAdv] - playPrefix[startAdv]
            if (currentScore > score) {
                score = currentScore
                result = startAdv
            }
            startAdv++
            endAdv++
        }
        return String.format("%02d:%02d:%02d", result / 60 / 60, (result / 60) % 60, result % 60)
    }
}