import java.util.*
class Solution {
    fun solution(clothes: Array<Array<String>>): Int {
        var answer = 1
        val closet = TreeMap<String, Int>()
        clothes.forEach { cloth -> closet[cloth[1]] = closet.getOrDefault(cloth[1], 0) + 1 }
        for (cloth in closet) answer *= (cloth.value + 1)
        return answer - 1
    }
}