import { CustomVector3 } from "../class/CustomVector3";

export const cubePointsL = [
  {
    x: -0.033946100050447,
    y: -0.014814765977542,
    z: -0.427301999697023,
    key: 436,
    enable: true,
  },
  {
    x: 0.101064271643822,
    y: -0.008423158618551,
    z: -0.402215705941105,
    key: 437,
    enable: true,
  },
  {
    x: -0.055234623914635,
    y: 0.109186031042987,
    z: -0.436685037949222,
    key: 438,
    enable: true,
  },
  {
    x: 0.031791031688248,
    y: 0.132273365452077,
    z: -0.420338134070974,
    key: 439,
    enable: true,
  },
].map((item) => new CustomVector3(+item.x, +item.y, +item.z));

export const cubePointsT = [
  {
    x: -0.120748875777717,
    y: 0.251411776795938,
    z: -0.043021866766229,
    key: 446,
    enable: true,
  },
  {
    x: -0.080360397753484,
    y: 0.222304890675973,
    z: -0.233697805555075,
    key: 447,
    enable: true,
  },
  {
    x: -0.120974481577464,
    y: 0.249881472008546,
    z: 0.099459224706702,
    key: 448,
    enable: true,
  },
  {
    x: -0.12098500925726,
    y: 0.224183160109905,
    z: 0.223062192862941,
    key: 449,
    enable: true,
  },
].map((item) => new CustomVector3(+item.x, +item.y, +item.z));

export const cubePointsR = [
  {
    x: -0.111205345855873,
    y: 0.023106552653109,
    z: 0.348459951806271,
    key: 462,
    enable: true,
  },
  {
    x: -0.111922633979727,
    y: -0.152254895849913,
    z: 0.350738425555756,
    key: 463,
    enable: true,
  },
  {
    x: 0.018881446438086,
    y: -0.151633451681865,
    z: 0.366202286745224,
    key: 464,
    enable: true,
  },
  {
    x: -0.23312139222727,
    y: -0.17190775857448,
    z: 0.344261700916617,
    key: 465,
    enable: true,
  },
].map((item) => new CustomVector3(+item.x, +item.y, +item.z));

export const cubePointsB = [
  {
    x: -0.087992054714451,
    y: -0.255328716110362,
    z: 0.198052654594207,
    key: 484,
    enable: true,
  },
  {
    x: 0.002917483256466,
    y: -0.253348907813688,
    z: 0.215169108925842,
    key: 485,
    enable: true,
  },
  {
    x: -0.021191189292589,
    y: -0.250567590558436,
    z: -0.284902874557863,
    key: 486,
    enable: true,
  },
  {
    x: 0.051530123723663,
    y: -0.254816194548353,
    z: -0.196203779298076,
    key: 487,
    enable: true,
  },
].map((item) => new CustomVector3(+item.x, +item.y, +item.z));

export const bounders = [
  {
    x: -0.170384797467504,
    y: -0.236421371891379,
    z: -0.441138447217589,
    key: 434,
    enable: true,
  },
  {
    x: 0.177891833212215,
    y: -0.238009972035096,
    z: -0.390257246826063,
    key: 435,
    enable: true,
  },
].map((item) => {
  return new CustomVector3(+item.x, +item.y, +item.z);
});
