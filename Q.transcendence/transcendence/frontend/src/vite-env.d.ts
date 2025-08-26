/// <reference types="vite/client" />

interface ImportMeta {
  readonly env: ImportMetaEnv;
  readonly hot: {
    accept: (callback?: () => void) => void;
    dispose: (callback: () => void) => void;
    decline: () => void;
    invalidate: () => void;
    data: any;
  };
}
