/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    arr1 = version1.split(".").map((el) => parseInt(el));
    arr2 = version2.split(".").map((el) => parseInt(el));

    let size = arr1.length > arr2.length ? arr2.length : arr1.length;
    for(let i = 0; i < size; i++){
        if(arr1[i] > arr2[i])
            return 1;
        else if(arr1[i] < arr2[i])
            return -1;
    }
    if(size === arr1.length && size != arr2.length){
        for(let i = size; i < arr2.length; i++){
            if(arr2[i] !== 0)
                return -1;
        }
    } else if(size === arr2.length && size != arr1.length){
        for(let i = size; i < arr1.length; i++){
            if(arr1[i] !== 0)
                return 1;
        }
    }

    return 0;
};