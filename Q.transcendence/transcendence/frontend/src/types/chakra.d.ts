import { ComponentWithAs } from "@chakra-ui/react"
import { LinkProps } from "react-router-dom"

declare module "@chakra-ui/react" {
  interface ButtonProps {
    to?: LinkProps["to"]
  }
}
