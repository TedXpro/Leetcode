/**
 * @param {number[]} people
 * @param {number} limit
 * @return {number}
 */
var numRescueBoats = function(people, limit) {
    people.sort((a,b) => a - b);
    let start = 0;
    let end = people.length - 1;
    let count = 0;
    console.log(people);
    while(start <= end){
        // if(people[end] === limit){
        //     end--;
        // }
        if(people[end] != limit && people[end] + people[start] <= limit) 
            start++;
        end--;
        count++;
    }
    return count;
};