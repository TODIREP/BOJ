import java.util.*
class Solution {
    fun solution(numbers: String): Int {
        val size = numbers.length
        val check = BooleanArray(size)
        val tree = TreeSet<Int>()
        
        fun search(cnt: Int, number: String) {
            if ((cnt <= size) and (cnt > 0)) {
                tree.add(number.toInt())
            }
            if (cnt == size) return
            
            repeat(size) loop@ {
                if (check[it]) return@loop
                check[it] = true
                search(cnt + 1, number + numbers[it])
                check[it] = false
            }
        }
        search(0, "")
        
        fun isSosu(target: Int): Boolean {
            if (target < 2) return false
            var num = 2
            while ((num * num) <= target) {
                if (target % num == 0) return false
                num++
            }
            return true
        }
        
        var answer = 0
        for (num in tree) {
            if (isSosu(num)) answer++
        }
        
        return answer
    }
}