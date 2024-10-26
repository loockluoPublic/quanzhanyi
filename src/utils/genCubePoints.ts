import * as THREE from "three";
import { CustomVector3 } from "../class/CustomVector3";

// 计算平面方程的函数（通过三个点确定平面方程 Ax + By + Cz + D = 0）
function calculatePlaneEquation(p1, p2, p3) {
  const v1 = new THREE.Vector3().subVectors(p2, p1);
  const v2 = new THREE.Vector3().subVectors(p3, p1);
  const normal = new THREE.Vector3().crossVectors(v1, v2);
  const d = -normal.dot(p1);
  return { normal, d };
}

// 判断点是否在多边形内部的函数，采用射线法（针对三维空间中的二维多边形投影到XY平面判断）
function isPointInPolygon(point, polygon) {
  let crossings = 0;

  for (let i = 0, j = polygon.length - 1; i < polygon.length; j = i++) {
    let xi = polygon[i].x,
      yi = polygon[i].y;
    let xj = polygon[j].x,
      yj = polygon[j].y;

    if (
      ((yi <= point.y && point.y < yj) || (yj <= point.y && point.y < yi)) &&
      point.x < ((xj - xi) * (point.y - yi)) / (yj - yi) + xi
    ) {
      crossings++;
    }
  }

  return crossings % 2 !== 0;
}

// 计算多边形面积的函数，采用鞋带公式（针对三维空间中的二维多边形投影到XY平面计算）
function polygonArea(polygon) {
  let area = 0;
  for (let i = 0, j = polygon.length - 1; i < polygon.length; j = i++) {
    area += (polygon[i].x + polygon[j].x) * (polygon[i].y - polygon[j].y);
  }
  return Math.abs(area / 2);
}

// 在三维空间的多边形内均匀生成点的函数
export function generateUniformPointsInPolygon(points, n) {
  // 拟合多边形所在平面（取前三个点计算平面方程）
  const planeInfo = calculatePlaneEquation(points[0], points[1], points[2]);
  const { normal, d } = planeInfo;

  // 将三维点投影到拟合平面上形成二维多边形（通过坐标变换）
  const polygon = points.map((point) => {
    const projectedPoint = new THREE.Vector3();
    const distance = (d - normal.dot(point)) / normal.z;
    projectedPoint.copy(point).addScaledVector(normal, distance);
    return new THREE.Vector2(projectedPoint.x, projectedPoint.y);
  });
  const area = polygonArea(polygon);

  const generatedPoints = [];

  // 计算二维投影多边形的宽度和高度
  let minX = Math.min(...polygon.map((p) => p.x));
  let maxX = Math.max(...polygon.map((p) => p.x));
  let minY = Math.min(...polygon.map((p) => p.y));
  let maxY = Math.max(...polygon.map((p) => p.y));
  let width = maxX - minX;
  let height = maxY - minY;

  // 计算每个小格子的边长（假设生成的点在多边形内近似均匀分布成小格子状）
  let cellSideX = (Math.sqrt(area / n) * width) / Math.sqrt(area);
  let cellSideY = (Math.sqrt(area / n) * height) / Math.sqrt(area);

  // 遍历每个小格子的中心位置生成点
  for (let i = 0; i < Math.ceil(width / cellSideX); i++) {
    for (let j = 0; j < Math.ceil(height / cellSideY); j++) {
      let x = minX + i * cellSideX + cellSideX / 2;
      let y = minY + j * cellSideY + cellSideY / 2;

      // 将生成的二维点还原到拟合平面上的三维空间点
      const z = (-d - normal.x * x - normal.y * y) / normal.z;
      const point = new CustomVector3(x, y, z);

      if (isPointInPolygon(point, polygon)) {
        generatedPoints.push(point);
      }
    }
  }

  return generatedPoints;
}

// 计算两点之间的距离（假设CustomVector3有合适的距离计算方法）
function distanceBetweenPoints(p1, p2) {
  return p1.distanceTo(p2);
}
function sortPointsByShortestPath(points) {
  if (points.length === 0) {
    return [];
  }
  const sortedPoints = [points[0]];
  const remainingPoints = points.slice(1);
  while (remainingPoints.length > 0) {
    let bestPointIndex = 0;
    let bestTotalDistance = Infinity;
    for (let i = 0; i < remainingPoints.length; i++) {
      let totalDistance = 0;
      for (let j = 0; j < sortedPoints.length; j++) {
        totalDistance += distanceBetweenPoints(
          sortedPoints[j],
          remainingPoints[i]
        );
      }
      if (totalDistance < bestTotalDistance) {
        bestTotalDistance = totalDistance;
        bestPointIndex = i;
      }
    }
    sortedPoints.push(remainingPoints[bestPointIndex]);
    remainingPoints.splice(bestPointIndex, 1);
  }
  return sortedPoints;
}

// 修改generateUniformPointsInPolygon函数，使其返回的点按最短路径排序
export function generateUniformPointsInPolygonWithSort(points, n) {
  const generatedPoints = generateUniformPointsInPolygon(points, n);
  return sortPointsByShortestPath(generatedPoints);
}
