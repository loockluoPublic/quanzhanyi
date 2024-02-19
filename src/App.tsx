import { useEffect, useRef, useState } from 'react'
import { Canvas, useFrame } from '@react-three/fiber'
import { OrbitControls } from '@react-three/drei'
import * as THREE from 'three'
import { useControls } from 'leva';

const points = [];
for ( let i = 0; i < 10; i ++ ) {
	points.push( new THREE.Vector2( Math.sin( i * 0.2 ) * 3 + 5, ( i - 5 ) * 2 ) );
}

console.log(points)

function Box(props) {
  // This reference gives us direct access to the THREE.Mesh object
  // const ref = useRef()
  // // Hold state for hovered and clicked events
  // const [hovered, hover] = useState(false)
  // const [clicked, click] = useState(false)
  // // Subscribe this component to the render-loop, rotate the mesh every frame
  // useFrame((state, delta) => (ref.current.rotation.x += delta))
  // // Return the view, these are regular Threejs elements expressed in JSX
  return (
    <mesh
      {...props}
      // ref={ref}
      // scale={clicked ? 1.5 : 1}
      // onClick={(event) => click(!clicked)}
      // onPointerOver={(event) => (event.stopPropagation(), hover(true))}
      // onPointerOut={(event) => hover(false)}
      >
      {/* <boxGeometry args={[1, 1, 1]} /> */}
      {/* <cylinderGeometry args={[ 5, 5, 20, 32]} /> */}
      <latheGeometry args={[points]}/>
      <meshBasicMaterial color={ '#00aec7'} side={THREE.DoubleSide} opacity={0.5} transparent={true}/>
    </mesh>
  )
}

export default function App() {
  const { name, aNumber,bluetooth } = useControls({ aNumber: 0, name: 'World',bluetooth:false });

  const getB = ()=>{
    
    
    navigator.bluetooth.requestDevice({acceptAllDevices:true}).then(function(device) {
      console.log('名称：' + device.name);
      // 在此处实现设备调用
    })
    .catch(function(error) {
      console.log("出现错误： " + error);
    });
  }

  // useEffect(()=>{
  //   console.log("bluetooth： " + bluetooth);
  //   if(bluetooth){
  //     getB()
  //   }
  // },[bluetooth])
  return (
    <>
      <button onClick={getB}>打开蓝牙</button>
    <Canvas dpr={window.devicePixelRatio}>
     <ambientLight intensity={Math.PI / 2} />
     <axesHelper args={[10]}/>
       {/* <spotLight position={[10, 10, 10]} angle={0.15} penumbra={1} decay={0} intensity={Math.PI} /> */}
      {/* <pointLight position={[-10, -10, -10]} decay={0} intensity={Math.PI} /> */}
      <Box position={[0, 0, 0]} />
      {/* <Box position={[1.2, 0, 0]} /> */}
      <OrbitControls />
    </Canvas>
    </>
  )
}
