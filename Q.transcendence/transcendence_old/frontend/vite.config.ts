import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'

export default defineConfig({
  plugins: [react()],
  resolve: {
    extensions: ['.ts', '.tsx', '.js', '.jsx']
  },
  server: {
    watch: {
      usePolling: true,
    },
    host: true, // Needed for the Docker Container port mapping to work
    strictPort: true,
    port: 5173, // you can remove this if you don't need it
  }
})
